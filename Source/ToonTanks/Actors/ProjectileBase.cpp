// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	//ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);  //Move this to begin play
	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = MovementSpeed;
	ProjectileMovement->MaxSpeed = MovementSpeed;
	InitialLifeSpan = 3.0f;

}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//Try to get a reference to the owning class
	AActor* MyOwner = GetOwner();
	// If for some reason we cant get a valid ref, return as we need to check against the owner
	if (!MyOwner)
	{
		return;
	}
	//If the other actor Isnt self or Owner and exists, then apply damage
	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwner->GetInstigatorController(), this, DamageType);
	}
	
	//Play sound effects

	Destroy();
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
}



