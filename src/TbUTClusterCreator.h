/*
 * TbUTClusterCreator.h
 *
 *  Created on: Jan 5, 2015
 *      Author: ADendek
 */

#pragma once

#include "TbUTIClusterCreator.h"
#include "TbUTITresholdProvider.h"

namespace TbUT
{

class ClusterCreator: public IClusterCreator
{
public:
	ClusterCreator(bool& p_isPtype, ITresholdProvider& p_thresholds);
	ClusterContainer::ClusterVector createClusters(RawData *p_inputData);

private:

	typedef ClusterContainer::ClusterVector::iterator ClusterIterator;

	void findCulsterSeeds(RawData *p_inputData);
	void removeDuplicatedSeeds(RawData *p_inputData);
	void extendClusterSeeds(RawData *p_inputData);

	bool isBiggerThanSeedThreshold(RawData::DataType p_channelSignal, int p_channel) const;
	Cluster createCluster(RawData *p_inputData, int l_channelNumber) const;

	bool arePartOfTheSameCluster(RawData* p_inputData, ClusterIterator& p_firstIt, ClusterIterator& p_secondIt) const;
	bool canBePartOfTheSameCluster(ClusterIterator& p_firstIt, ClusterIterator& p_secondIt) const;

	void extendCluster(ClusterIterator& p_clusterIt, RawData* p_inputData);
	void removeClusterSeedWithSmallerCharge(ClusterIterator& p_firstIt, ClusterIterator& p_secondIt);
	bool hasNotMaximumSize(ClusterIterator& p_clusterIt) const;
	bool isStripNeedToBeAddedToCluster(ClusterIterator& p_clusterIt, RawData *p_inputData,int p_stripShift, bool p_isCheckingLeft  ) const;
	void updateCluster(ClusterIterator& p_clusterIt,RawData *p_inputData ,int p_stripShift, bool p_isCheckingLeft);
	bool isInvalidChannelNumber(int p_stripShift) const;
	bool isBiggerThanLowThreshold(RawData::DataType p_channelSignal, int p_chnnel) const;
	void normalizeClusterPosition(ClusterIterator& p_clusterIt);
	void fillOuterStrips(RawData *p_inputData);


	bool& m_isPtype;
	const int m_clusterMaxSize;
	ITresholdProvider& m_thresholds;
	ClusterContainer::ClusterVector m_culsterVector;
};


} /* namespace TbUT */

