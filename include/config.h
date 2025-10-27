/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#define VERSION "1.2.1"

// ===== DEBUG Settings ===== //
// #define ENABLE_DEBUG
#define DEBUG_PORT Serial
#define DEBUG_BAUD 115200

// ===== Storage Settings ===== //
#define READ_BUFFER 2048

// ===== Parser Settings ===== //
#define CASE_SENSETIVE false
#define DEFAULT_SLEEP 5

// ===== Other Stuff ====== //
#define PREFERENCES_PATH "preferences.json"