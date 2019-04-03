// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"
#include "Animation/AnimInstance.h"
#include "MazeRunnerProjectile.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Creates a new subobject names FP_GUN
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_GUN"));
	//Makes it so only owner can see
	FP_Gun->SetOnlyOwnerSee(true);
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	//Where to attatch the muzzle location
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

}

void AGun::OnFire()
{
	if (ProjectileClass != NULL)
	{
		UWorld* const world = GetWorld();

		if (world != NULL)
		{
			const FRotator SpawnRotation = FP_MuzzleLocation->GetComponentRotation();
			//MuzzleOffset set from characters location
			const FVector SpawnLocation = FP_MuzzleLocation->GetComponentLocation();
			//Set spawn collision override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
			//Spawn the projectile at the muzzle depending on rotation, location and the params
			world->SpawnActor<AMazeRunnerProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}
	if (FireSound != NULL) 
	{
		//Plays the sound at this actors location, using firesound.
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}
	if (FireAnimation !=NULL)
	{
		if(AnimInstance !=NULL)
		{
			//Runs the animation montage we have set with the speed of 1f
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

