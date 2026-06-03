// Copyright Clint Zhou

#pragma once

#include "CoreMinimal.h"
#include "Character/AureCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAureCharacterBase
{
	GENERATED_BODY()
public:
	AAuraCharacter();
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
private:
	virtual void InitAbilityActorInfo() override;
};
