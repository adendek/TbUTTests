#include "gmock/gmock.h"
#include "TbUTITresholdProvider.h"


namespace TbUT {

class MockITresholdProvider : public ITresholdProvider {
 public:
  MOCK_METHOD0(retreiveTresholds, void());
  MOCK_METHOD1(getLowClusterThreshold, double(int p_channel));
  MOCK_METHOD1(getHighClusterThreshold, double(int p_channel));
};

}  // namespace TbUT

