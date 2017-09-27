// Copyright (c) 2017 Franka Emika GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#pragma once

#include <cstdint>
#include <ostream>

#include <franka/duration.h>

/**
 * @file gripper_state.h
 * Contains the franka::GripperState type.
 */

namespace franka {

/**
 * Describes the gripper state.
 */
struct GripperState {
  /**
   * Current gripper opening width.
   */
  double width{};

  /**
   * Maximum gripper opening width.
   * This parameter is estimated by homing the gripper.
   * After changing the gripper fingers, a homing needs to be done.
   *
   * @see Gripper::homing.
   */
  double max_width{};

  /**
   * Indicates whether an object is currently grasped.
   */
  bool is_grasped{};

  /**
   * Current gripper temperature in °C.
   */
  uint16_t temperature{};

  /**
   * Strictly increasing time for each received gripper state.
   */
  Duration time{};
};

/**
 * Streams the gripper state as JSON object: {"field_name_1": value, "field_name_2": value, ...}
 */
std::ostream& operator<<(std::ostream& ostream, const franka::GripperState& gripper_state);

}  // namespace franka
