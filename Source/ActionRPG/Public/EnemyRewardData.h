// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonDataAssetBase.h"
#include "EnemyRewardData.generated.h"

/**
 * 
 */
UCLASS(BluePrintType)
class ACTIONRPG_API UEnemyRewardData : public UJsonDataAssetBase
{
	GENERATED_BODY()

public:
        UEnemyRewardData();

		UPROPERTY(BluePrintReadOnly, EditAnywhere = Reward)
		float TimeBonusPerKill;

	    UPROPERTY(BluePrintReadOnly, EditAnywhere = Reward)
	    int MinSoulsDropped;

		UPROPERTY(BluePrintReadOnly, EditAnywhere = Reward)
		int MaxSoulsDropped;

		UPROPERTY(BluePrintReadOnly, EditAnywhere = Reward)
		float PotionDropChance;

		virtual TSharedPtr<FJsonObject> ToJson() override;
		virtual bool FromJson(FJsonObject& jsonObject)override;
	
};
