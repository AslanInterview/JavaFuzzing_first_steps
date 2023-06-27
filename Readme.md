
# Temporary repository hosting the dockerfiles for the java fuzzer


## docker build

    docker build . -t test_java_fuzzing

## run docker

    docker run -it test_java_fuzzing


## Inside the docker run this to start the fuzzing


    cargo run -F tui 2>/dev/null


Using "2>/dev/null" because the test cases write logs to stderr, so we want to skip them 
because it will break our tui view. 
Note that redirecting stderr to **/dev/null** will result the abscense of cargo building output.
So instead, you can first run 

    cargo build


And then

    cargo run -F tui 2>/dev/null