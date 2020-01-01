/*
 * Rules.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#ifndef RULES_H_
#define RULES_H_

#include "Defs.h"
#include "Card.h"
#include "Hand.h"

// split up this file

class Strategy {
public:
	virtual ~Strategy() {}
	virtual Action Decide(const Card& up_card, const Hand& hand) = 0;
};

class BasicStrategyDealerHitsSoft17 : public Strategy {
public:
	Action Decide(const Card& up_card, const Hand& hand) override;
};

class BasicStrategyDealerStaysSoft17 : public Strategy {
public:
	Action Decide(const Card& up_card, const Hand& hand) override;
};

class AverageBasicStrategy : public Strategy {
public:
	Action Decide(const Card& up_card, const Hand& hand) override;
};

class PoorBasicStrategy : public Strategy {
public:
	Action Decide(const Card& up_card, const Hand& hand) override;
};

class DealerStrategy {
public:
	virtual ~DealerStrategy() {}
	virtual Action Decide(const Hand& hand) = 0;
};

class DealerHitsSoft17 : public DealerStrategy {
public:
	Action Decide(const Hand& hand) override;
};

class DealerStaysSoft17 : public DealerStrategy {
public:
	Action Decide(const Hand& hand) override;
};

class BetStrategy {
public:
	virtual ~BetStrategy() {}

	virtual bool IsIn(int true_count) = 0;
	virtual int GetMultiplier(int true_count) = 0;
};

class ScalingWongingBetStrategy : public BetStrategy  {
public:
	bool IsIn(int true_count) override;
	int GetMultiplier(int true_count) override;
};

class AverageBetStrategy : public BetStrategy {
public:
	bool IsIn(int true_count) override;
	int GetMultiplier(int true_count) override;
};

class FlatBetStrategy : public BetStrategy {
public:
	bool IsIn(int true_count) override;
	int GetMultiplier(int true_count) override;
};

#endif /* RULES_H_ */
