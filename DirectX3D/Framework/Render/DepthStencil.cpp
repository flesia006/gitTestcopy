#include "Framework.h"
#include "DepthStencil.h"

DepthStencil::DepthStencil(UINT width, UINT height, bool isStencil)
	:width(width), height(height), isStencil(isStencil)
{
	CreateDSVTexture();
	CreateDSV();
	CreateSRV();
}

DepthStencil::~DepthStencil()
{
	dsvTexture->Release();
	dsv->Release();
	srv->Release();

}

void DepthStencil::Clear()
{
	DC->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH, 1, 0);

}

void DepthStencil::CreateDSVTexture()
{
	// ���� ���Ľ� ���¸� �غ��ϰ�, �ش� ȭ���� ���� �ؽ���ó�� �ٹ̱�
	D3D11_TEXTURE2D_DESC depthDesc = {};
	// ���� ������ �ɼ� ����
	depthDesc.Width = width;
	depthDesc.Height = height;
	depthDesc.MipLevels = 1;
	depthDesc.ArraySize = 1;
	depthDesc.Format = isStencil ? DXGI_FORMAT_R24G8_TYPELESS : DXGI_FORMAT_R32_TYPELESS;
	depthDesc.Usage = D3D11_USAGE_DEFAULT;
	depthDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL | D3D11_BIND_SHADER_RESOURCE;
	// ���ε� �÷��� : ���� ���� ���ٽ�, ���̴� ���ҽ� �ɼ��� �����ϴ� ������ ����

	DEVICE->CreateTexture2D(&depthDesc, nullptr, &dsvTexture);

}

void DepthStencil::CreateDSV()
{
	// �ؽ�ó �����͸� ������� �� �׸��� ���� ���� �غ� ����
	D3D11_DEPTH_STENCIL_VIEW_DESC depthViewDesc = {};
	depthViewDesc.Format = isStencil ? DXGI_FORMAT_D24_UNORM_S8_UINT : DXGI_FORMAT_D32_FLOAT;
	depthViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	
	DEVICE->CreateDepthStencilView(dsvTexture, &depthViewDesc, &dsv); // ����, ������, ��� ���� ��ġ

}

void DepthStencil::CreateSRV()
{
	D3D11_SHADER_RESOURCE_VIEW_DESC desc = {};
	desc.Format = isStencil ? DXGI_FORMAT_R24_UNORM_X8_TYPELESS : DXGI_FORMAT_R32_FLOAT;
	// ���Ľ��̸� ���� ���ٽǿ� ���� �κ��� ����� ����
	desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	desc.Texture2D.MipLevels = 1;

	DEVICE->CreateShaderResourceView(dsvTexture, &desc, &srv);

}
