import torch

# Create a tensor
x = torch.tensor([1, 2, 3, 4, 5])

# Perform some operations
y = x + 2
z = torch.sin(y)

# Print the results
print(x)
print(y)
print(z)
from torchvision.models import densenet121

# DenseNet 모델 정의
class DenseNetRegressor(nn.Module):
    def __init__(self):
        super(DenseNetRegressor, self).__init__()
        self.densenet = densenet121(pretrained=False)
        self.fc = nn.Linear(1000, 1)  # DenseNet121의 출력 크기는 1000

    def forward(self, x):
        out = self.densenet(x)
        out = self.fc(out)
        return out

# 모델, 손실 함수, 옵티마이저 초기화
model = DenseNetRegressor()
criterion = nn.MSELoss()
optimizer = optim.Adam(model.parameters(), lr=learning_rate)

# 모델 학습
for epoch in range(num_epochs):
    for i, (inputs, labels) in enumerate(dataloader):
        # Forward pass
        outputs = model(inputs)
        loss = criterion(outputs, labels)
        
        # Backward and optimize
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        
        if (i+1) % 100 == 0:
            print(f'Epoch [{epoch+1}/{num_epochs}], Step [{i+1}/{len(dataloader)}], Loss: {loss.item():.4f}')

print("모델 학습 완료")