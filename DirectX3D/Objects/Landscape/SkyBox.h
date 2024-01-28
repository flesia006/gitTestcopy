#pragma once
class SkyBox : public Sphere
{
	// 3D  ������ �ִ� ���α׷����� �ϴ��� ������ �����ϱ� ���� ��ġ�� ���� ����
	// ��ī�� �ڽ��� Ư¡ :  �ؽ��İ� ���� ����
	// ��Ʋ�� :  ��������, ���� �̹����� ���忡 ���� ū �׸� ����. ��ü�� ��� �ؽ��� 1��

public:
	SkyBox(wstring file);
	~SkyBox();

	void Render();

private:	
	Texture* skyMap;
	RasterizerState* rasterizerState[2];
	// ������ ���� ���ַ� ������� �̹����� ���� ��,
	// �ȼ��� �ٲ��ִ� ���� ���������� �ܰ�

	DepthStencilState* depthStencilState[2];
	// ���� + ���ٽ� ����
	// : �ȼ� Ȥ�� ���̴� ������ �� �ȼ��� ��� �켱������ �����ϴ� depth ���¿�
	// ȭ���� ��� ���� ���θ� �������� �����ϴ� ���Ľ� ���¸� 
	// �ϳ��� ������� ������ ��

	// 


};
