// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "EnemyRewardData.h"


UEnemyRewardData::UEnemyRewardData()
{
	TimeBonusPerKill = 5.0F;
	MinSoulsDropped = 5;
	MaxSoulsDropped = 10;
	PotionDropChance = 0.1F;
}

TSharedPtr<FJsonObject> UEnemyRewardData::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<JsonObject>();

	jsonObject->SetNumberField("time_bonus_per_kill", TimeBonusPerKill);
	jsonObject->SetNumberField("min_souls_dropped", MinSoulsDropped);
	jsonObject->SetNumberField("max_souls_dropped", MaxSoulsDropped);
	jsonObject->SetNumberField("potion_drop_chance", PotionDropChance);

	return jsonObject;
}

bool UEnemyRewardData::FromJson(FJsonObject& jsonObject)
{
	TimeBonusPerKill = jsonObject.GetNumberField("time_bonus_per_kill");
	MinSoulsDropped = jsonObject.GetNumberField("min_souls_dropped");
	MaxSoulsDropped = jsonObject.GetNumberField("max_sould_dropped");
	PotionDropChance = jsonObject.GetNumberField("potion_drop_chance");
	return true;

}


