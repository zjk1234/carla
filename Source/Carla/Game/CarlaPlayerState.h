// CARLA, Copyright (C) 2017 Computer Vision Center (CVC)

#pragma once

#include "GameFramework/PlayerState.h"
#include "CapturedImage.h"
#include "CarlaPlayerState.generated.h"

/// Current state of the player, updated every frame by ACarlaVehicleController.
///
/// This class matches the reward that it is sent to the client over the
/// network.
UCLASS()
class CARLA_API ACarlaPlayerState : public APlayerState
{
  GENERATED_BODY()

  // ===========================================================================
  // -- Types ------------------------------------------------------------------
  // ===========================================================================
public:


  // ===========================================================================
  // -- APlayerState -----------------------------------------------------------
  // ===========================================================================
public:

  virtual void Reset() override;

  virtual void CopyProperties(APlayerState *PlayerState) override;

  // ===========================================================================
  // -- Getters ----------------------------------------------------------------
  // ===========================================================================
public:

  UFUNCTION()
  int32 GetTimeStamp() const
  {
    return TimeStamp;
  }

  UFUNCTION()
  const FVector &GetLocation() const
  {
    return Location;
  }

  UFUNCTION()
  const FVector &GetOrientation() const
  {
    return Orientation;
  }

  UFUNCTION()
  const FVector &GetAcceleration() const
  {
    return Acceleration;
  }

  UFUNCTION()
  float GetForwardSpeed() const
  {
    return ForwardSpeed;
  }

  UFUNCTION()
  int32 GetCurrentGear() const
  {
    return CurrentGear;
  }

  UFUNCTION()
  float GetCollisionIntensityCars() const
  {
    return CollisionIntensityCars;
  }

  UFUNCTION()
  float GetCollisionIntensityPedestrians() const
  {
    return CollisionIntensityPedestrians;
  }

  UFUNCTION()
  float GetCollisionIntensityOther() const
  {
    return CollisionIntensityOther;
  }

  UFUNCTION()
  float GetOtherLaneIntersectionFactor() const
  {
    return OtherLaneIntersectionFactor;
  }

  UFUNCTION()
  float GetOffRoadIntersectionFactor() const
  {
    return OffRoadIntersectionFactor;
  }

  UFUNCTION()
  const TArray<FCapturedImage> &GetImages() const
  {
    return Images;
  }

  // ===========================================================================
  // -- Modifiers --------------------------------------------------------------
  // ===========================================================================
private:

  void RegisterCollision(AActor *Actor, FVector NormalImpulse);

  void UpdateTimeStamp();

  // ===========================================================================
  // -- Private members --------------------------------------------------------
  // ===========================================================================
private:

  friend class ACarlaVehicleController;

  // If you add another variable here, don't forget to copy it inside
  // CopyProperties if necessary.

  UPROPERTY(VisibleAnywhere)
  int32 TimeStamp;

  UPROPERTY(VisibleAnywhere)
  FVector Location;

  UPROPERTY(VisibleAnywhere)
  FVector Orientation;

  UPROPERTY(VisibleAnywhere)
  FVector Acceleration;

  UPROPERTY(VisibleAnywhere)
  int32 CurrentGear;

  UPROPERTY(VisibleAnywhere)
  float ForwardSpeed = 0.0f;

  UPROPERTY(VisibleAnywhere)
  float CollisionIntensityCars = 0.0f;

  UPROPERTY(VisibleAnywhere)
  float CollisionIntensityPedestrians = 0.0f;

  UPROPERTY(VisibleAnywhere)
  float CollisionIntensityOther = 0.0f;

  UPROPERTY(VisibleAnywhere)
  float OtherLaneIntersectionFactor = 0.0f;

  UPROPERTY(VisibleAnywhere)
  float OffRoadIntersectionFactor = 0.0f;

  UPROPERTY(VisibleAnywhere)
  TArray<FCapturedImage> Images;
};
