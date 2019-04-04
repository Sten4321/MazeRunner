// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class MAZERUNNER_API AGun : public AActor
{
	GENERATED_BODY()
	//Category means which category these functions are under, like redering, physics and so on
	//The gun mesh only to be seen by yourself in first person
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;
	//The loction of where bullets should spawn
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;
public:
	//Projectile to spawn
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AMazeRunnerProjectile> ProjectileClass;
	//Sound we use when we fire a projectile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;
	//Montage of animations we play when fire
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimInstance* AnimInstance;
	// Sets default values for this actor's properties
	AGun();
	void OnFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
