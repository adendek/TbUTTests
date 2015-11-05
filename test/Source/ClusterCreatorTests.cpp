/*
 * ClusterCreatorTests.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: ja
 */
#include "TbUTTresholdProviderMock.h"
#include "TbUTClusterCreator.h"

using namespace TbUT;
using namespace ::testing;

class ClusterCreatorTests: public Test {
public:
	ClusterCreatorTests();

    virtual void setUp() { }
    virtual void tearDown(){};

    bool m_isPtype;
    MockITresholdProvider m_thresholdMock;
	ClusterCreator m_clusterCreator;

	ClusterContainer::ClusterVector runClusterization(RawData::SignalVector signalVector)
	{
		RawData* data=new RawData();
		data->setSignal(signalVector);
		expectThresholdsValues(150,200);
		ClusterContainer::ClusterVector outputVector=m_clusterCreator.createClusters(data);
		delete data;
		return outputVector;
	}

	void expectThresholdsValues(double thresholdLowValue, double thresholdHighValue ){
		EXPECT_CALL(m_thresholdMock,getHighClusterThreshold(_))
				.WillRepeatedly(Return(thresholdHighValue));

		EXPECT_CALL(m_thresholdMock,getLowClusterThreshold(_))
				.WillRepeatedly(Return(thresholdLowValue));
	}

	void expectClustersVectorSize(ClusterContainer::ClusterVector createdClusters ,int size){
		EXPECT_EQ(createdClusters.size(),size);
	}

	void expectClusterParameters(Cluster& cluster, int size, double charge, double seedPosition){
		EXPECT_EQ(cluster.m_size,size);
		EXPECT_EQ(cluster.m_charge,charge);
		EXPECT_EQ(cluster.m_seedPosition,seedPosition);
	}

};

ClusterCreatorTests::ClusterCreatorTests():
		m_isPtype(true),
		m_thresholdMock(),
		m_clusterCreator(m_isPtype,m_thresholdMock)
{
}

TEST_F(ClusterCreatorTests, ShouldCreateZeroClusters)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-190; // below high threshol value

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,0);
}

TEST_F(ClusterCreatorTests, ShouldCreateOneSingleCluster)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-250;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,1,-250,100);
}

TEST_F(ClusterCreatorTests, ShouldCreateSingleClustersCloseToEachOther)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[10]=-250;
	signal[12]=-250;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,2);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,1,-250,10);
	cluster=createdClusters[1];
	expectClusterParameters(cluster,1,-250,12);
}

TEST_F(ClusterCreatorTests, ShouldCreateDoubleClustersLowLeft)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-250;
	signal[101]=-160;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,2,-410,100);
}

TEST_F(ClusterCreatorTests, ShouldCreateDoubleClustersLowRight)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-250;
	signal[99]=-160;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,2,-410,100);
}

TEST_F(ClusterCreatorTests, ShouldCreateDoubleClustersTwoChannelsAboveHighThreshold)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[200]=-210;
	signal[201]=-250;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,2,-460,201);
}

TEST_F(ClusterCreatorTests, ShouldCreateTwoDoubleClustersCloseToEachOther)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-210;
	signal[101]=-250;
	signal[102]=-110; // below low threshold
	signal[103]=-250;
	signal[104]=-210;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,2);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,2,-460,101);
	cluster=createdClusters[1];
	expectClusterParameters(cluster,2,-460,103);
}

TEST_F(ClusterCreatorTests, ShouldCreateTripleSymetricCluster)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-160;
	signal[101]=-250; // seed
	signal[102]=-160;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,3,-570,101);
}
// Bug need to be fix!
TEST_F(ClusterCreatorTests, ShouldCreateTripleSymetricClusterAllStripsAboveHighThreshold)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-210;
	signal[101]=-250; //real seed
	signal[102]=-210;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,3,-670,101);
}

TEST_F(ClusterCreatorTests, ShouldCreateTripleSymetricClusterTwoStripsAboveHighThreshold)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-250; //seed
	signal[101]=-160;
	signal[102]=-210;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,3,-620,100);
}

TEST_F(ClusterCreatorTests, ShouldCreateQuadrupleSymetricCluster)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-160;
	signal[101]=-160;
	signal[102]=-250; //seed
	signal[103]=-160;


	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,4,-730,102);
}

TEST_F(ClusterCreatorTests, ShouldCreateQuadrupleSymetricClusterAllStripsAboveHighThreshold)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-210;
	signal[101]=-210;
	signal[102]=-250; //seed
	signal[103]=-210;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,4,-880,102);
}

TEST_F(ClusterCreatorTests, ShouldCreateQuadrupleSymetricClusterOuterStripsAboveHighThreshold)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-250; //seed
	signal[101]=-160;
	signal[102]=-160;
	signal[103]=-210;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,4,-780,100);
}

TEST_F(ClusterCreatorTests, ShouldCreateQuadrupleSymetricClusterInnerStripsAboveHighThreshold)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-160;
	signal[101]=-210;
	signal[102]=-250;//seed
	signal[103]=-160;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,4,-780,102);
}

TEST_F(ClusterCreatorTests, ShouldCreateQuadrupleSymetricClusterThreeStripsAboveHighThreshold)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-160;
	signal[101]=-210;
	signal[102]=-250;//seed
	signal[103]=-210;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,1);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,4,-830,102);
}

TEST_F(ClusterCreatorTests, ShouldCreateTwoQuadrupleClustersClostToEachOther)
{
	RawData::SignalVector signal=RawData::SignalVector(512,0);
	signal[100]=-160;
	signal[101]=-210;
	signal[102]=-250;//first seed
	signal[103]=-210;
	signal[104]=-140; // below low threshold
	signal[105]=-160;
	signal[106]=-210;
	signal[107]=-250;//seed
	signal[108]=-210;

	ClusterContainer::ClusterVector createdClusters=runClusterization(signal);
	expectClustersVectorSize(createdClusters,2);
	Cluster cluster=createdClusters[0];
	expectClusterParameters(cluster,4,-830,102);
	cluster=createdClusters[1];
	expectClusterParameters(cluster,4,-830,107);
}
