#ifndef TestCase_hpp
#define TestCase_hpp

namespace TestModule {
	class TestCase {
		public: virtual bool passed() = 0;
	};
}

#endif