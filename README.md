# Reflection System Practice
리플렉션 시스템 실습

# 프로젝트 소개
-  **언리얼C++** 과 엔진 기능 (Actor, Tick, 리플렉션 시스템 등)을 활용해 **간단한 퍼즐 스테이지**를 구현
- **회전 발판**, **이동 플랫폼** 등 **동적으로 움직이는 오브젝트**를 만들고, 이를 **C++ 로직**과 **Tick 함수**로 제어하여 언리얼 C++ 개발 흐름을 체득
- **리플렉션 시스템**을 통해 변수 (속도, 범위, 각도 등)를 **에디터에서 수정**할 수 있도록 노출하여 효율적인 게임플레이 튜닝 과정을 경험

# 구현 리스트

## C++ Actor 클래스 구현

- 2개의 C++ Actor 클래스
- 각 클래스는 **StaticMeshComponent**를 갖고 있으며, Static Mesh와 Material을 직접 넣어주었습니다.

## Tick 함수 활용한 회전 및 이동 로직 작성

- frame마다 호출되는 Tick함수를 이용해 액터의 회전, 이동 로직을 구현하기로 하였습니다.

- 하지만, 컴퓨터마다 성능이 다르므로 Tick함수에서 단순히 회전값, 이동값을 추가해주면 안 되겠다고 생각하였습니다.

- 따라서, DeltaTime을 이용하여 물리적인 성능 차이를 해결하고자 하였습니다.

- **회전**
    - `Tick(float DeltaTime)`에서 `AddActorLocalRotation()` 사용
    - `RotationSpeed` 변수를 활용하여 초당 회전 각도를 결정
- **이동**
    - `Tick(float DeltaTime)`에서 위치를 변경하여 **왕복 이동** 구현
    - 이를 위해 `StartLocation`과 `MaxRange`를 설정하여, 매 Tick함수에서 액터가 이동한 범위를 확인
    - 일정 범위 이상이라면 이동 속도인 `MoveSpeed`의 값을 반전시켜주어 왕복 이동을 구현

## 리플렉션 시스템 적용

- `UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform Settings")` 형태로 주요 변수를 에디터에서 조정할 수 있도록 노출
- 리플렉션 시스템을 이용하여 게임 플레이 도중 **Details 패널**에서 편집 가능하도록 구현

# 시연 영상

https://github.com/user-attachments/assets/ee513ca1-5b56-449e-ba66-e7b1f5b3446f


