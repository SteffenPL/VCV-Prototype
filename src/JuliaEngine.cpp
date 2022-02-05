#include "ScriptEngine.hpp"
#include <julia.h>


struct JuliaEngine : ScriptEngine {

	~JuliaEngine() {
	    //jl_atexit_hook(0);
	}

	std::string getEngineName() override {
		return "Julia";
	}


	int run(const std::string& path, const std::string& script) override {
		//ProcessBlock* block = getProcessBlock();

		display("Julia engine (run) V2.");
		
	    jl_init();

        return 0;
    }

    
	int process() override {
		ProcessBlock* block = getProcessBlock();

		for( int i = 0; i < MAX_BUFFER_SIZE; ++i)
			block->outputs[0][i] = 5.0f * i / MAX_BUFFER_SIZE;

		block->lights[0][0] = 5.0f;
		block->lights[0][1] = 10.0f;

		return 0;
	}
};


__attribute__((constructor(1000)))
static void constructor() {
	addScriptEngine<JuliaEngine>(".jl");
}
