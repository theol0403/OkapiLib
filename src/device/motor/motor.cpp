/**
 * @author Ryan Benasutti, WPI
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "okapi/device/motor/motor.hpp"

namespace okapi {
Motor::Motor(const uint8_t port, const bool reverse, const motor_encoder_units_e_t encoder_units,
             const motor_gearset_e_t gearset)
  : pros::Motor(port, gearset, reverse, encoder_units) {
}

std::int32_t Motor::moveAbsolute(const double iposition, const std::int32_t ivelocity) const {
  return move_absolute(iposition, ivelocity);
}

std::int32_t Motor::moveRelative(const double iposition, const std::int32_t ivelocity) const {
  return move_relative(iposition, ivelocity);
}

std::int32_t Motor::moveVelocity(const std::int16_t ivelocity) const {
  return move_velocity(ivelocity);
}

std::int32_t Motor::moveVoltage(const std::int16_t ivoltage) const {
  return move_voltage(ivoltage);
}

double Motor::getTargetPosition() const {
  return get_target_position();
}

double Motor::getPosition() const {
  return get_position();
}

std::int32_t Motor::getTargetVelocity() const {
  return get_target_velocity();
}

double Motor::getActualVelocity() const {
  return get_actual_velocity();
}

std::int32_t Motor::setZeroPosition(const double iposition) const {
  return set_zero_position(iposition);
}

std::int32_t Motor::setBrakeMode(const motor_brake_mode_e_t imode) const {
  return set_brake_mode(imode);
}

std::int32_t Motor::setCurrentLimit(const std::int32_t ilimit) const {
  return set_current_limit(ilimit);
}

std::int32_t Motor::setEncoderUnits(const motor_encoder_units_e_t iunits) const {
  return set_encoder_units(iunits);
}

std::int32_t Motor::setGearing(const motor_gearset_e_t igearset) const {
  return set_gearing(igearset);
}

std::int32_t Motor::setReversed(const bool ireverse) const {
  return set_reversed(ireverse);
}

std::int32_t Motor::setVoltageLimit(const std::int32_t ilimit) const {
  return set_voltage_limit(ilimit);
}

IntegratedEncoder Motor::getEncoder() const {
  return IntegratedEncoder(*this);
}

void Motor::controllerSet(const double ivalue) {
  move_velocity(ivalue);
}

inline namespace literals {
okapi::Motor operator"" _m(const unsigned long long iport) {
  return okapi::Motor(static_cast<uint8_t>(iport));
}

okapi::Motor operator"" _rm(const unsigned long long iport) {
  return okapi::Motor(static_cast<uint8_t>(iport));
}
} // namespace literals
} // namespace okapi