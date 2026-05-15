// Copyright Clint Zhou

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AureCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AAureCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAureCharacterBase();

protected:
	virtual void BeginPlay() override;
	
	
	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
