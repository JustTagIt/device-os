set(target_name cellular)

# Generate include path
include_directories(
  ${DEVICE_OS_DIR}/hal/inc/
  ${DEVICE_OS_DIR}/hal/shared/
  ${DEVICE_OS_DIR}/hal/src/electron/
  ${DEVICE_OS_DIR}/services/inc/
  ${DEVICE_OS_DIR}/wiring/inc/
)

# Create test executable
add_executable( ${target_name}
  ${DEVICE_OS_DIR}/hal/src/electron/cellular_internal.cpp
  ${DEVICE_OS_DIR}/wiring/src/spark_wiring_cellular_printable.cpp
  ${DEVICE_OS_DIR}/wiring/src/spark_wiring_print.cpp
  cellular.cpp
)

# Set defines specific to target
target_compile_definitions( ${target_name}
  PRIVATE PLATFORM_ID=10
)

# Set compiler flags specific to target
target_compile_options( ${target_name}
  PRIVATE -fno-inline -fprofile-arcs -ftest-coverage -O0 -g
)

# Link against dependencies specific to target

# Add tests to `test` target
catch_discover_tests( ${target_name}
  TEST_PREFIX ${target_name}_
)
