#include <Arduino.h>
#include <Config.h>
#include <Scheduler.h>
#include <LCD.h>
#include <WPM.h>
#include <GameManager.h>
#include <Games/BinaryMath.h>
#include <Games/LedSequence.h>
#include <Games/MorseCodeTranslator.h>
#include <Games/VoltMatcher.h>

static unsigned long lastMicros = 0;
static double lastDeltaTime = 0.0;
static bool started = false;

Scheduler scheduler;
GameManager gameManager;

LCD lcd{LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS, scheduler};
WPM wpm{WPM_STB, WPM_CLK, WPM_DIO, scheduler};

void initialize() {
    // Clear scheduler tasks
    scheduler.clearTasks();

    // Reset timings
    lastMicros = micros();
    lastDeltaTime = 0.0;

    // Register the games
    gameManager.registerGame(std::make_unique<MorseCodeTranslator>(scheduler, lcd));
    gameManager.registerGame(std::make_unique<VoltMatcher>());
    gameManager.registerGame(std::make_unique<LedSequence>());
    gameManager.registerGame(std::make_unique<BinaryMath>());

    // Register the game transitions
    gameManager.registerTransition<MorseCodeTranslator, VoltMatcher>();
    gameManager.registerTransition<VoltMatcher, LedSequence>();
    gameManager.registerTransition<LedSequence, BinaryMath>();

    // Set the current game as starting game
    started = gameManager.switchGame<MorseCodeTranslator>();
}

void setup() {
    Serial.begin(BAUD_RATE);

    // Initialization
    initialize();
}

void loop() {
    // Skip if not started
    if (!started) return;

    // Calculate the delta time
    const unsigned long currentMicros = micros();
    const unsigned long elapsed = currentMicros - lastMicros;
    double deltaTime = static_cast<double>(elapsed) / 1e6;
    if (deltaTime > 0.25) deltaTime = 0.25;

    // Execute the tasks
    scheduler.execute();

    // Loop the current game
    gameManager.loop();

    // Make a transition if necessary
    gameManager.transition();

    lastMicros = currentMicros;
    lastDeltaTime = deltaTime;

    static unsigned long lastLog = 0;
    if (currentMicros - lastLog >= 1e6) {
        lastLog = currentMicros;

        // Log the delta time in milliseconds formatted to 4 decimal places every second
        // Serial.print("Delta time: " + String(lastDeltaTime * 1e3, 4) + "ms\n");
        Game::count++;
        Serial.print("Count: " + String(Game::count) + "\n");
    }
}
