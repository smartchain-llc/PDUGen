#include <PDUGenTest.h>

#include <Header/PDUHeader.h>
#include <istream>
#include <streambuf>
#include <string>

TEST(PDUHeader, BitSize) { EXPECT_EQ(sizeof(PDUHeader_t) * 8, 96); }

struct PDUHeaderStream : public std::streambuf {
  PDUHeaderStream() : std::streambuf() {
    char buf[sizeof(PDUHeader_t) * 12];

    this->setbuf(buf, sizeof(buf));
  }
};

TEST(PDUHeader, CanReadFromByteStream) {
  char buffer[1024];
  PDUHeaderStream str;
  std::cout << "PDUHeaderStream avail: " << str.in_avail() << std::endl;
}
int main() { pdg_test::run_all_tests(); }