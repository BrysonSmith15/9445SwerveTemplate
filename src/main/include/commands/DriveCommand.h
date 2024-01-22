// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/button/CommandJoystick.h>

#include <functional>

#include "RobotContainer.h"
#include "subsystems/Drivetrain.h"

/**
 * This command implements typical drive
 * using the 2024 swerve drive chassis
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class DriveCommand : public frc2::CommandHelper<frc2::Command, DriveCommand> {
 public:
  /**
   * Creates a new Drive.
   *
   * @param drivetrain The drivetrain class used by this command.
   */
  DriveCommand(Drivetrain* drivetrain, RobotContainer* robotContainer);
  void Execute() override;
  void End(bool interrupted) override;

 private:
  Drivetrain* drivetrain;
  // this is probably bad practice, but it is more practical
  RobotContainer* robot;
};
