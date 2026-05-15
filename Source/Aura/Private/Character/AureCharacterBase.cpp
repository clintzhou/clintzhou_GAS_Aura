// Copyright Clint Zhou

#include "Character/AureCharacterBase.h"

// Sets default values
AAureCharacterBase::AAureCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	
	
}

void AAureCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	 
}


