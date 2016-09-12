%:src/%.cpp
	@mkdir -p bin
	g++ -std=c++11 -g $^ -o bin/$@

clean:
	@echo "cleaning..."
	@rm bin/*
