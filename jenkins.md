# Jenkins notes
**Freestyle** jobs are simpler than **Pipeline** jobs, which require the Pipeline plugin.


A Jenkinsfile should exist in the root directory of the project
Jenkinsfile has 3 stages:<sup>[ref](https://youtu.be/kW_bADC2fFM?t=330)</sup>
- `stage('Build')`
- `stage('Test')`
- `stage('Deliver')`
