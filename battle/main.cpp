#include <igloo/igloo_alt.h>
#include "igloo/CodewarsTestListener.h"

using namespace igloo;

int main(int, char **) {
	std::cout << "\n\nRunning Test Suite\n" << std::endl;
	ColoredConsoleTestResultsOutput output{};
	TestRunner runner{output};
	CodewarsTestListener listener{};
	runner.AddListener(&listener);
	return runner.Run();
}