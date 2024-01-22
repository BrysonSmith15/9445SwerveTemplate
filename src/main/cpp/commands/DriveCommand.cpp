// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCommand.h"

#include <utility>

DriveCommand::DriveCommand(Drivetrain* drivetrain,
                           RobotContainer* robotContainer)
    : drivetrain{drivetrain}, robot{robotContainer} {
  // Register that this command requires the subsystem.
  AddRequirements(this->drivetrain);
}

void DriveCommand::Execute() {
  // assumes field oriented
  auto states = this->drivetrain->m_kinematics.ToSwerveModuleStates(
      frc::ChassisSpeeds::FromFieldRelativeSpeeds(
          this->robot->getXState(), this->robot->getYState(),
          this->robot->getThetaState(), this->drivetrain->getGyroAngle()));

  this->drivetrain->m_kinematics.DesaturateWheelSpeeds(
      &states, this->drivetrain->MAXSPEED);

  this->drivetrain->setStates(states);
}

void DriveCommand::End(bool interrupted) { this->drivetrain->Stop(); }