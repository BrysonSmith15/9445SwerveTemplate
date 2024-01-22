// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() {
  // Implementation of subsystem constructor goes here.
}

frc2::CommandPtr Drivetrain::Stop() {
  return this->RunOnce([this] {
    flModule.stop();
    frModule.stop();
    blModule.stop();
    brModule.stop();
  });
}

void Drivetrain::setStates(wpi::array<frc::SwerveModuleState, 4U> states) {
  auto [fl, fr, bl, br] = states;
  flModule.setState(fl);
  frModule.setState(fr);
  blModule.setState(bl);
  brModule.setState(br);
}

units::angle::radian_t Drivetrain::getGyroAngle() {
  // this is needed because the NavX reads from 0-360 and beyond, not [-180,
  // 180], which does not work with the other code
  /*
  units::angle::radian_t angle =
      this->gyro.GetAngle() * (std::numbers::pi / 180.0) * 1_rad;
  angle = fmod(angle.value(), 360.0) * 1_rad;
  return angle < 180_deg ? angle : angle - 2_rad * std::numbers::pi;
  */
  return 0_rad;
}

void Drivetrain::Periodic() {
  m_odometry.Update(this->getGyroAngle(),
                    {flModule.GetPosition(), frModule.GetPosition(),
                     blModule.GetPosition(), brModule.GetPosition()});
}
