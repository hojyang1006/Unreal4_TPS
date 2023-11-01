// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WeaponType.h"
#include "ShooterAnimInstance.generated.h"

UENUM(BlueprintType)
enum class EOffsetState : uint8
{
	EOS_Aiming UMETA(DisplayName = "Aiming"),
	EOS_Hip UMETA(DisplayName = "Hip"),
	EOS_Reloading UMETA(DisplayName = "Reloading"),
	EOS_InAir UMETA(DisplayName = "InAir"),


	EOS_MAX UMETA(DisplayName = "DefaultMAX")
};


/**
 * 
 */
UCLASS()
class SHOOTER_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UShooterAnimInstance();


	UFUNCTION(BlueprintCallable)
		void UpdateAnimationProperties(float DeltaTime);

		virtual void NativeInitializeAnimation() override;

protected:

	void TurnInPlace();

	void Lean(float DeltaTime);


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		class AShooterCharacter* ShooterCharacter;

	//캐릭터의 속도
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		float Speed;

	//캐릭터가 공중에 있는지 여부 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		bool bIsInAir;

	//캐릭터의 이동 여부
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		bool bIsAccelerating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = "true"))
		float MovementOffsetYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = "true"))
		float LastMovementOffsetYaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		bool bAiming;

	float TIPCharacterYaw;

	float TIPCharacterYawLastFrame;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turn In Place", meta = (AllowPrivateAccess = "true"))
		float RootYawOffset;


	float RotationCurve;

	float RotationCurveLastFrame;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turn In Place", meta = (AllowPrivateAccess = "true"))
		float Pitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turn In Place", meta = (AllowPrivateAccess = "true"))
		bool bReloading;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turn In Place", meta = (AllowPrivateAccess = "true"))
		EOffsetState OffsetState;

	FRotator CharacterRotation;

	FRotator CharacterRotationLastFrame;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Lean, meta = (AllowPrivateAccess = "true"))
		float YawDelta;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Crouching, meta = (AllowPrivateAccess = "true"))
		bool bCrouching;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Crouching, meta = (AllowPrivateAccess = "true"))
		bool bEquipping;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Crouching, meta = (AllowPrivateAccess = "true"))
		float RecoilWeight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
		bool bTurningInPlace;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
		EWeaponType EquippedWeaponType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
		bool bShouldUseFABRIK;

};
