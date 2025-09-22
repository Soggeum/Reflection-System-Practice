# Reflection System Practice

# 프로젝트 소개
- **언리얼 C++**과 엔진 기능 (Actor, Tick, 리플렉션 시스템 등)을 활용해 **간단한 퍼즐 스테이지**를 구현
- **회전 발판**, **이동 플랫폼** 등 **동적으로 움직이는 오브젝트**를 만들고, 이를 **C++ 로직**과 **Tick 함수**로 제어하여 언리얼 C++ 개발 흐름을 체득
- **리플렉션 시스템**을 통해 변수 (속도, 범위, 각도 등)를 **에디터에서 수정**할 수 있도록 노출하여 효율적인 게임플레이 튜닝 과정을 경험

# 구현 리스트

## C++ Actor 클래스 구현

- 2개의 C++ Actor 클래스
- 각 클래스는 **StaticMeshComponent**를 갖고 있으며, Static Mesh와 Material을 직접 넣어주었습니다.

## Tick 함수 활용한 회전 및 이동 로직 작성

- **회전**
    - `Tick(float DeltaTime)`에서 `AddActorLocalRotation()` 사용
    - `RotationSpeed` 변수를 활용하여 초당 회전 각도를 결정
- **이동**
    - `Tick(float DeltaTime)`에서 위치를 변경하여 **왕복 이동** 구현
    - `StartLocation`, `MoveSpeed`, `MaxRange` 등을 고려해 일정 범위 안에서 이동
    - 일정 범위를 벗어나면 이동 방향을 반전시키는 로직 구성
    - **프레임 독립적** 움직임을 위해 반드시 `DeltaTime`을 이용

## 리플렉션 시스템 적용

- `UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform Settings")` 형태로 주요 변수를 에디터에서 조정할 수 있도록 노출

## 테스트

- 플레이 모드에서 **오브젝트가 의도대로 움직이는지**, **속도 변경이 실시간 반영되는지** 등을 확인
- 리플렉션 시스템을 이용하여 게임 플레이 도중 **Details 패널**에서 편집 가능하도록 구현

# 시연 영상



https://github.com/user-attachments/assets/ee513ca1-5b56-449e-ba66-e7b1f5b3446f


