pipeline{
  agent any
  stages{
    stage('Clone repository'){
        steps{
          checkout([
            $class: 'GitSCM',
            branches: [{name: '*/main'}],
            userRemoteConfigs: [[url: 'https://github.com/NavyaPeram/PES1UG21CS924_Jenkins.git']]
          ])
        }
    }

    stage('Build'){
        steps{
            build 'PES1UG21CS924-1'
            sh 'g++ hello2.cpp -o output'
        }
    }

    stage('Test'){
        steps{
            sh './output'
        }
    }

    stage('Deploy'){
        steps{
            echo 'deploy'
        }
    }
  }
  post{
    failure{
        error 'Pipeline failed'
    }
  }
}


    


