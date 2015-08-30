#include "BsBuiltinResources.h"
#include "BsGUIElementStyle.h"

#include "BsGUILabel.h"
#include "BsGUIButton.h"
#include "BsGUIInputBox.h"
#include "BsGUIToggle.h"
#include "BsGUIDropDownContent.h"
#include "BsTextSprite.h"
#include "BsSpriteTexture.h"

#include "BsFont.h"
#include "BsFontImportOptions.h"
#include "BsImporter.h"
#include "BsResources.h"
#include "BsGpuProgram.h"
#include "BsShader.h"
#include "BsShaderInclude.h"
#include "BsTechnique.h"
#include "BsPass.h"
#include "BsMaterial.h"
#include "BsBlendState.h"
#include "BsDepthStencilState.h"
#include "BsRTTIType.h"
#include "BsFileSystem.h"
#include "BsCoreApplication.h"
#include "BsCoreThread.h"
#include "BsApplication.h"
#include "BsDataStream.h"
#include "BsTime.h"
#include "BsResourceManifest.h"

namespace BansheeEngine
{
	const WString BuiltinResources::DefaultFontFilename = L"arial.ttf";
	const UINT32 BuiltinResources::DefaultFontSize = 10;

	const WString BuiltinResources::GUISkinFile = L"GUISkin";

	const Path BuiltinResources::CursorFolder = L"Cursors\\";
	const Path BuiltinResources::ShaderFolder = L"Shaders\\";
	const Path BuiltinResources::SkinFolder = L"Skin\\";
	const Path BuiltinResources::ShaderIncludeFolder = L"Includes\\";

	const Path BuiltinResources::BuiltinRawDataFolder = RUNTIME_DATA_PATH + L"Raw\\Engine\\";
	const Path BuiltinResources::EngineRawSkinFolder = BuiltinRawDataFolder + SkinFolder;
	const Path BuiltinResources::EngineRawCursorFolder = BuiltinRawDataFolder + CursorFolder;
	const Path BuiltinResources::EngineRawShaderFolder = BuiltinRawDataFolder + ShaderFolder;
	const Path BuiltinResources::EngineRawShaderIncludeFolder = BuiltinRawDataFolder + ShaderIncludeFolder;

	const Path BuiltinResources::BuiltinDataFolder = RUNTIME_DATA_PATH + L"Engine\\";
	const Path BuiltinResources::EngineSkinFolder = BuiltinDataFolder + SkinFolder;
	const Path BuiltinResources::EngineCursorFolder = BuiltinDataFolder + CursorFolder;
	const Path BuiltinResources::EngineShaderFolder = BuiltinDataFolder + ShaderFolder;
	const Path BuiltinResources::EngineShaderIncludeFolder = BuiltinDataFolder + ShaderIncludeFolder;

	const Path BuiltinResources::ResourceManifestPath = BuiltinDataFolder + "ResourceManifest.asset";

	/************************************************************************/
	/* 								GUI TEXTURES                      		*/
	/************************************************************************/

	const WString BuiltinResources::WhiteTex = L"White.psd";

	const WString BuiltinResources::ButtonNormalTex = L"ButtonNormal.psd";
	const WString BuiltinResources::ButtonHoverTex = L"ButtonHover.psd";
	const WString BuiltinResources::ButtonActiveTex = L"ButtonActive.psd";

	const WString BuiltinResources::ToggleNormalTex = L"ToggleNormal.psd";
	const WString BuiltinResources::ToggleHoverTex = L"ToggleHover.psd";
	const WString BuiltinResources::ToggleActiveTex = L"ToggleActive.psd";
	const WString BuiltinResources::ToggleNormalOnTex = L"ToggleOnNormal.psd";
	const WString BuiltinResources::ToggleHoverOnTex = L"ToggleOnHover.psd";
	const WString BuiltinResources::ToggleActiveOnTex = L"ToggleOnActive.psd";

	const WString BuiltinResources::InputBoxNormalTex = L"InputBoxNormal.psd";
	const WString BuiltinResources::InputBoxHoverTex = L"InputBoxHover.psd";
	const WString BuiltinResources::InputBoxFocusedTex = L"InputBoxFocused.psd";

	const WString BuiltinResources::ScrollBarUpNormalTex = L"ScrollBarUpNormal.psd";
	const WString BuiltinResources::ScrollBarUpHoverTex = L"ScrollBarUpHover.psd";
	const WString BuiltinResources::ScrollBarUpActiveTex = L"ScrollBarUpActive.psd";

	const WString BuiltinResources::ScrollBarDownNormalTex = L"ScrollBarDownNormal.psd";
	const WString BuiltinResources::ScrollBarDownHoverTex = L"ScrollBarDownHover.psd";
	const WString BuiltinResources::ScrollBarDownActiveTex = L"ScrollBarDownActive.psd";

	const WString BuiltinResources::ScrollBarLeftNormalTex = L"ScrollBarLeftNormal.psd";
	const WString BuiltinResources::ScrollBarLeftHoverTex = L"ScrollBarLeftHover.psd";
	const WString BuiltinResources::ScrollBarLeftActiveTex = L"ScrollBarLeftActive.psd";

	const WString BuiltinResources::ScrollBarRightNormalTex = L"ScrollBarRightNormal.psd";
	const WString BuiltinResources::ScrollBarRightHoverTex = L"ScrollBarRightHover.psd";
	const WString BuiltinResources::ScrollBarRightActiveTex = L"ScrollBarRightActive.psd";

	const WString BuiltinResources::ScrollBarHandleHorzNormalTex = L"ScrollBarHorzHandleNormal.psd";
	const WString BuiltinResources::ScrollBarHandleHorzHoverTex = L"ScrollBarHorzHandleHover.psd";
	const WString BuiltinResources::ScrollBarHandleHorzActiveTex = L"ScrollBarHorzHandleActive.psd";

	const WString BuiltinResources::ScrollBarHandleVertNormalTex = L"ScrollBarVertHandleNormal.psd";
	const WString BuiltinResources::ScrollBarHandleVertHoverTex = L"ScrollBarVertHandleHover.psd";
	const WString BuiltinResources::ScrollBarHandleVertActiveTex = L"ScrollBarVertHandleActive.psd";

	const WString BuiltinResources::DropDownBtnNormalTex = L"DropDownNormal.psd";
	const WString BuiltinResources::DropDownBtnHoverTex = L"DropDownHover.psd";

	const WString BuiltinResources::DropDownBoxBgTex = L"DropDownBoxBg.psd";
	const WString BuiltinResources::DropDownBoxEntryNormalTex = L"DropDownButtonNormal.psd";
	const WString BuiltinResources::DropDownBoxEntryHoverTex = L"DropDownButtonHover.psd";

	const WString BuiltinResources::DropDownBoxBtnUpNormalTex = L"DropDownBoxBtnUpNormal.psd";
	const WString BuiltinResources::DropDownBoxBtnUpHoverTex = L"DropDownBoxBtnUpHover.psd";

	const WString BuiltinResources::DropDownBoxBtnDownNormalTex = L"DropDownBoxBtnDownNormal.psd";
	const WString BuiltinResources::DropDownBoxBtnDownHoverTex = L"DropDownBoxBtnDownHover.psd";

	const WString BuiltinResources::DropDownBoxEntryExpNormalTex = L"DropDownExpNormal.psd";
	const WString BuiltinResources::DropDownBoxEntryExpHoverTex = L"DropDownExpHover.psd";

	const WString BuiltinResources::DropDownSeparatorTex = L"DropDownSeparator.psd";

	const WString BuiltinResources::DropDownBoxBtnUpArrowTex = L"DropDownBoxBtnUpArrow.psd";
	const WString BuiltinResources::DropDownBoxBtnDownArrowTex = L"DropDownBoxBtnDownArrow.psd";

	const WString BuiltinResources::ScrollBarBgTex = L"ScrollBarBg.psd";

	/************************************************************************/
	/* 							CURSOR TEXTURES                      		*/
	/************************************************************************/

	const WString BuiltinResources::CursorArrowTex = L"Arrow.psd";
	const WString BuiltinResources::CursorArrowDragTex = L"ArrowDrag.psd";
	const WString BuiltinResources::CursorArrowLeftRightTex = L"ArrowLeftRight.psd";
	const WString BuiltinResources::CursorIBeamTex = L"IBeam.psd";
	const WString BuiltinResources::CursorDenyTex = L"Deny.psd";
	const WString BuiltinResources::CursorWaitTex = L"Wait.psd";
	const WString BuiltinResources::CursorSizeNESWTex = L"SizeNESW.psd";
	const WString BuiltinResources::CursorSizeNSTex = L"SizeNS.psd";
	const WString BuiltinResources::CursorSizeNWSETex = L"SizeNWSE.psd";
	const WString BuiltinResources::CursorSizeWETex = L"SizeWE.psd";

	const Vector2I BuiltinResources::CursorArrowHotspot = Vector2I(11, 8);
	const Vector2I BuiltinResources::CursorArrowDragHotspot = Vector2I(11, 8);
	const Vector2I BuiltinResources::CursorArrowLeftRightHotspot = Vector2I(9, 4);
	const Vector2I BuiltinResources::CursorIBeamHotspot = Vector2I(15, 15);
	const Vector2I BuiltinResources::CursorDenyHotspot = Vector2I(15, 15);
	const Vector2I BuiltinResources::CursorWaitHotspot = Vector2I(15, 15);
	const Vector2I BuiltinResources::CursorSizeNESWHotspot = Vector2I(15, 15);
	const Vector2I BuiltinResources::CursorSizeNSHotspot = Vector2I(15, 15);
	const Vector2I BuiltinResources::CursorSizeNWSEHotspot = Vector2I(15, 15);
	const Vector2I BuiltinResources::CursorSizeWEHotspot = Vector2I(15, 15);

	/************************************************************************/
	/* 									SHADERS                      		*/
	/************************************************************************/

	const WString BuiltinResources::ShaderSpriteTextFile = L"SpriteText.bsl";
	const WString BuiltinResources::ShaderSpriteImageAlphaFile = L"SpriteImageAlpha.bsl";
	const WString BuiltinResources::ShaderSpriteImageNoAlphaFile = L"SpriteImageNoAlpha.bsl";
	const WString BuiltinResources::ShaderDiffuseFile = L"Diffuse.bsl";
	const WString BuiltinResources::ShaderDummyFile = L"Dummy.bsl";

	BuiltinResources::~BuiltinResources()
	{
		mCursorArrow = nullptr;
		mCursorArrowDrag = nullptr;
		mCursorArrowLeftRight = nullptr;
		mCursorIBeam = nullptr;
		mCursorDeny = nullptr;
		mCursorWait = nullptr;
		mCursorSizeNESW = nullptr;
		mCursorSizeNS = nullptr;
		mCursorSizeNWSE = nullptr;
		mCursorSizeWE = nullptr;
	}

	BuiltinResources::BuiltinResources()
	{
		Path absoluteDataPath = FileSystem::getWorkingDirectoryPath();
		absoluteDataPath.append(BuiltinDataFolder);

		if (FileSystem::exists(ResourceManifestPath))
			mResourceManifest = ResourceManifest::load(ResourceManifestPath, absoluteDataPath);

		if (mResourceManifest == nullptr)
			mResourceManifest = ResourceManifest::create("BuiltinResources");

		gResources().registerResourceManifest(mResourceManifest);

#if BS_DEBUG_MODE
		if (BuiltinResourcesHelper::checkForModifications(BuiltinRawDataFolder, BuiltinDataFolder + L"Timestamp.asset"))
		{
			preprocess();
			BuiltinResourcesHelper::writeTimestamp(BuiltinDataFolder + L"Timestamp.asset");

			Path absoluteDataPath = FileSystem::getWorkingDirectoryPath();
			absoluteDataPath.append(BuiltinDataFolder);

			ResourceManifest::save(mResourceManifest, ResourceManifestPath, absoluteDataPath);
		}
#endif
		
		mShaderSpriteText = getShader(ShaderSpriteTextFile);
		mShaderSpriteImage = getShader(ShaderSpriteImageAlphaFile);
		mShaderSpriteNonAlphaImage = getShader(ShaderSpriteImageNoAlphaFile);
		mShaderDiffuse = getShader(ShaderDiffuseFile);
		mShaderDummy = getShader(ShaderDummyFile);

		mWhiteSpriteTexture = getSkinTexture(WhiteTex);

		mSkin = gResources().load<GUISkin>(BuiltinDataFolder + (GUISkinFile + L".asset"));

		/************************************************************************/
		/* 								CURSOR		                     		*/
		/************************************************************************/

		HTexture cursorArrowTex = getCursorTexture(CursorArrowTex);
		HTexture cursorArrowDragTex = getCursorTexture(CursorArrowDragTex);
		HTexture cursorArrowLeftRightTex = getCursorTexture(CursorArrowLeftRightTex);
		HTexture cursorIBeamTex = getCursorTexture(CursorIBeamTex);
		HTexture cursorDenyTex = getCursorTexture(CursorDenyTex);
		HTexture cursorWaitTex = getCursorTexture(CursorWaitTex);
		HTexture cursorSizeNESWTex = getCursorTexture(CursorSizeNESWTex);
		HTexture cursorSizeNSTex = getCursorTexture(CursorSizeNSTex);
		HTexture cursorSizeNWSETex = getCursorTexture(CursorSizeNWSETex);
		HTexture cursorSizeWETex = getCursorTexture(CursorSizeWETex);

		mCursorArrow = cursorArrowTex->getProperties().allocateSubresourceBuffer(0);
		cursorArrowTex->readSubresource(gCoreAccessor(), 0, mCursorArrow);

		mCursorArrowDrag = cursorArrowDragTex->getProperties().allocateSubresourceBuffer(0);
		cursorArrowDragTex->readSubresource(gCoreAccessor(), 0, mCursorArrowDrag);

		mCursorArrowLeftRight = cursorArrowLeftRightTex->getProperties().allocateSubresourceBuffer(0);
		cursorArrowLeftRightTex->readSubresource(gCoreAccessor(), 0, mCursorArrowLeftRight);

		mCursorIBeam = cursorIBeamTex->getProperties().allocateSubresourceBuffer(0);
		cursorIBeamTex->readSubresource(gCoreAccessor(), 0, mCursorIBeam);

		mCursorDeny = cursorDenyTex->getProperties().allocateSubresourceBuffer(0);
		cursorDenyTex->readSubresource(gCoreAccessor(), 0, mCursorDeny);

		mCursorWait = cursorWaitTex->getProperties().allocateSubresourceBuffer(0);
		cursorWaitTex->readSubresource(gCoreAccessor(), 0, mCursorWait);

		mCursorSizeNESW = cursorSizeNESWTex->getProperties().allocateSubresourceBuffer(0);
		cursorSizeNESWTex->readSubresource(gCoreAccessor(), 0, mCursorSizeNESW);

		mCursorSizeNS = cursorSizeNSTex->getProperties().allocateSubresourceBuffer(0);
		cursorSizeNSTex->readSubresource(gCoreAccessor(), 0, mCursorSizeNS);

		mCursorSizeNWSE = cursorSizeNWSETex->getProperties().allocateSubresourceBuffer(0);
		cursorSizeNWSETex->readSubresource(gCoreAccessor(), 0, mCursorSizeNWSE);

		mCursorSizeWE = cursorSizeWETex->getProperties().allocateSubresourceBuffer(0);
		cursorSizeWETex->readSubresource(gCoreAccessor(), 0, mCursorSizeWE);

		gCoreAccessor().submitToCoreThread(true);
	}

	void BuiltinResources::preprocess()
	{
		FileSystem::remove(EngineCursorFolder);
		FileSystem::remove(EngineShaderIncludeFolder);
		FileSystem::remove(EngineShaderFolder);
		FileSystem::remove(EngineSkinFolder);

		BuiltinResourcesHelper::importAssets(EngineRawCursorFolder, EngineCursorFolder, mResourceManifest);
		BuiltinResourcesHelper::importAssets(EngineRawShaderIncludeFolder, EngineShaderIncludeFolder, mResourceManifest); // Hidden dependency: Includes must be imported before shaders
		BuiltinResourcesHelper::importAssets(EngineRawShaderFolder, EngineShaderFolder, mResourceManifest);
		BuiltinResourcesHelper::importAssets(EngineRawSkinFolder, EngineSkinFolder, mResourceManifest);

		// Import font
		BuiltinResourcesHelper::importFont(BuiltinRawDataFolder + DefaultFontFilename, BuiltinDataFolder, DefaultFontSize, false, mResourceManifest);

		// Generate & save GUI sprite textures
		BuiltinResourcesHelper::generateSpriteTextures(EngineSkinFolder, mResourceManifest);

		// Generate & save GUI skin
		{
			HGUISkin skin = generateGUISkin();
			Path outputPath = FileSystem::getWorkingDirectoryPath() + BuiltinDataFolder + (GUISkinFile + L".asset");
			Resources::instance().save(skin, outputPath, true);
			mResourceManifest->registerResource(skin.getUUID(), outputPath);
		}
		
		Resources::instance().unloadAllUnused();
	}

	HGUISkin BuiltinResources::generateGUISkin()
	{
		Path fontPath = FileSystem::getWorkingDirectoryPath();
		fontPath.append(BuiltinDataFolder);
		fontPath.append(DefaultFontFilename + L".asset");

		HFont font = Resources::instance().load<Font>(fontPath);
		HGUISkin skin = GUISkin::create();

		// Label
		GUIElementStyle labelStyle;
		labelStyle.font = font;
		labelStyle.fontSize = DefaultFontSize;
		labelStyle.fixedWidth = false;
		labelStyle.fixedHeight = true;
		labelStyle.height = 11;
		labelStyle.minWidth = 10;

		skin->setStyle(GUILabel::getGUITypeName(), labelStyle);

		// Button
		GUIElementStyle buttonStyle;
		buttonStyle.normal.texture = getSkinTexture(ButtonNormalTex);
		buttonStyle.hover.texture = getSkinTexture(ButtonHoverTex);
		buttonStyle.active.texture = getSkinTexture(ButtonActiveTex);
		buttonStyle.border.left = 6;
		buttonStyle.border.right = 6;
		buttonStyle.border.top = 6;
		buttonStyle.border.bottom = 6;
		buttonStyle.contentOffset.left = 3;
		buttonStyle.contentOffset.right = 3;
		buttonStyle.fixedHeight = true;
		buttonStyle.height = 15;
		buttonStyle.minWidth = 50;
		buttonStyle.font = font;
		buttonStyle.fontSize = DefaultFontSize;
		buttonStyle.textHorzAlign = THA_Center;
		buttonStyle.textVertAlign = TVA_Center;

		skin->setStyle(GUIButton::getGUITypeName(), buttonStyle);

		// Toggle
		GUIElementStyle toggleStyle;
		toggleStyle.normal.texture = getSkinTexture(ToggleNormalTex);
		toggleStyle.hover.texture = getSkinTexture(ToggleHoverTex);
		toggleStyle.active.texture = getSkinTexture(ToggleActiveTex);
		toggleStyle.normalOn.texture = getSkinTexture(ToggleNormalOnTex);
		toggleStyle.hoverOn.texture = getSkinTexture(ToggleHoverOnTex);
		toggleStyle.activeOn.texture = getSkinTexture(ToggleActiveOnTex);
		toggleStyle.fixedHeight = true;
		toggleStyle.fixedWidth = true;
		toggleStyle.height = 15;
		toggleStyle.width = 15;

		skin->setStyle(GUIToggle::getGUITypeName(), toggleStyle);

		// Input box
		GUIElementStyle inputBoxStyle;
		inputBoxStyle.normal.texture = getSkinTexture(InputBoxNormalTex);
		inputBoxStyle.hover.texture = getSkinTexture(InputBoxHoverTex);
		inputBoxStyle.focused.texture = getSkinTexture(InputBoxFocusedTex);
		inputBoxStyle.active.texture = inputBoxStyle.normal.texture;
		inputBoxStyle.border.left = 1;
		inputBoxStyle.border.right = 1;
		inputBoxStyle.border.top = 1;
		inputBoxStyle.border.bottom = 1;
		inputBoxStyle.contentOffset.left = 3;
		inputBoxStyle.contentOffset.right = 3;
		inputBoxStyle.contentOffset.top = 2;
		inputBoxStyle.contentOffset.bottom = 2;
		inputBoxStyle.fixedHeight = true;
		inputBoxStyle.height = 15;
		inputBoxStyle.minWidth = 10;
		inputBoxStyle.font = font;
		inputBoxStyle.fontSize = DefaultFontSize;
		inputBoxStyle.textHorzAlign = THA_Left;
		inputBoxStyle.textVertAlign = TVA_Top;

		skin->setStyle(GUIInputBox::getGUITypeName(), inputBoxStyle);

		/************************************************************************/
		/* 								SCROLL BAR                      		*/
		/************************************************************************/

		// Up button
		GUIElementStyle scrollUpBtnStyle;
		scrollUpBtnStyle.normal.texture = getSkinTexture(ScrollBarUpNormalTex);
		scrollUpBtnStyle.hover.texture = getSkinTexture(ScrollBarUpHoverTex);
		scrollUpBtnStyle.active.texture = getSkinTexture(ScrollBarUpActiveTex);
		scrollUpBtnStyle.fixedHeight = true;
		scrollUpBtnStyle.fixedWidth = true;
		scrollUpBtnStyle.height = 4;
		scrollUpBtnStyle.width = 8;

		skin->setStyle("ScrollUpBtn", scrollUpBtnStyle);

		// Down button
		GUIElementStyle scrollDownBtnStyle;
		scrollDownBtnStyle.normal.texture = getSkinTexture(ScrollBarDownNormalTex);
		scrollDownBtnStyle.hover.texture = getSkinTexture(ScrollBarDownHoverTex);
		scrollDownBtnStyle.active.texture = getSkinTexture(ScrollBarDownActiveTex);
		scrollDownBtnStyle.fixedHeight = true;
		scrollDownBtnStyle.fixedWidth = true;
		scrollDownBtnStyle.height = 4;
		scrollDownBtnStyle.width = 8;

		skin->setStyle("ScrollDownBtn", scrollDownBtnStyle);

		// Left button
		GUIElementStyle scrollLeftBtnStyle;
		scrollLeftBtnStyle.normal.texture = getSkinTexture(ScrollBarLeftNormalTex);
		scrollLeftBtnStyle.hover.texture = getSkinTexture(ScrollBarLeftHoverTex);
		scrollLeftBtnStyle.active.texture = getSkinTexture(ScrollBarLeftActiveTex);
		scrollLeftBtnStyle.fixedHeight = true;
		scrollLeftBtnStyle.fixedWidth = true;
		scrollLeftBtnStyle.height = 8;
		scrollLeftBtnStyle.width = 4;

		skin->setStyle("ScrollLeftBtn", scrollLeftBtnStyle);

		// Right button
		GUIElementStyle scrollRightBtnStyle;
		scrollRightBtnStyle.normal.texture = getSkinTexture(ScrollBarRightNormalTex);
		scrollRightBtnStyle.hover.texture = getSkinTexture(ScrollBarRightHoverTex);
		scrollRightBtnStyle.active.texture = getSkinTexture(ScrollBarRightActiveTex);
		scrollRightBtnStyle.fixedHeight = true;
		scrollRightBtnStyle.fixedWidth = true;
		scrollRightBtnStyle.height = 8;
		scrollRightBtnStyle.width = 4;

		skin->setStyle("ScrollRightBtn", scrollRightBtnStyle);

		// Horizontal handle
		GUIElementStyle scrollBarHorzBtnStyle;
		scrollBarHorzBtnStyle.normal.texture = getSkinTexture(ScrollBarHandleHorzNormalTex);
		scrollBarHorzBtnStyle.hover.texture = getSkinTexture(ScrollBarHandleHorzHoverTex);
		scrollBarHorzBtnStyle.active.texture = getSkinTexture(ScrollBarHandleHorzActiveTex);
		scrollBarHorzBtnStyle.fixedHeight = true;
		scrollBarHorzBtnStyle.fixedWidth = true;
		scrollBarHorzBtnStyle.height = 6;
		scrollBarHorzBtnStyle.width = 4;

		skin->setStyle("ScrollBarHorzBtn", scrollBarHorzBtnStyle);

		// Vertical handle
		GUIElementStyle scrollBarVertBtnStyle;
		scrollBarVertBtnStyle.normal.texture = getSkinTexture(ScrollBarHandleVertNormalTex);
		scrollBarVertBtnStyle.hover.texture = getSkinTexture(ScrollBarHandleVertHoverTex);
		scrollBarVertBtnStyle.active.texture = getSkinTexture(ScrollBarHandleVertActiveTex);
		scrollBarVertBtnStyle.fixedHeight = true;
		scrollBarVertBtnStyle.fixedWidth = true;
		scrollBarVertBtnStyle.height = 4;
		scrollBarVertBtnStyle.width = 6;

		skin->setStyle("ScrollBarVertBtn", scrollBarVertBtnStyle);

		HSpriteTexture scrollBarBgPtr = getSkinTexture(ScrollBarBgTex);

		// Vertical scroll bar
		GUIElementStyle vertScrollBarStyle;
		vertScrollBarStyle.normal.texture = scrollBarBgPtr;
		vertScrollBarStyle.hover.texture = scrollBarBgPtr;
		vertScrollBarStyle.active.texture = scrollBarBgPtr;
		vertScrollBarStyle.fixedHeight = false;
		vertScrollBarStyle.fixedWidth = true;
		vertScrollBarStyle.minHeight = 16;
		vertScrollBarStyle.width = 8;

		skin->setStyle("ScrollBarVert", vertScrollBarStyle);

		// Horizontal scroll bar
		GUIElementStyle horzScrollBarStyle;
		horzScrollBarStyle.normal.texture = scrollBarBgPtr;
		horzScrollBarStyle.hover.texture = scrollBarBgPtr;
		horzScrollBarStyle.active.texture = scrollBarBgPtr;
		horzScrollBarStyle.fixedHeight = true;
		horzScrollBarStyle.fixedWidth = false;
		horzScrollBarStyle.minWidth = 16;
		horzScrollBarStyle.height = 8;

		skin->setStyle("ScrollBarHorz", horzScrollBarStyle);

		/************************************************************************/
		/* 								DROP DOWN BOX                      		*/
		/************************************************************************/

		// ListBox button
		GUIElementStyle dropDownListStyle;
		dropDownListStyle.normal.texture = getSkinTexture(DropDownBtnNormalTex);
		dropDownListStyle.hover.texture = getSkinTexture(DropDownBtnHoverTex);
		dropDownListStyle.active.texture = dropDownListStyle.hover.texture;
		dropDownListStyle.normalOn.texture = dropDownListStyle.hover.texture;
		dropDownListStyle.hoverOn.texture = dropDownListStyle.hover.texture;
		dropDownListStyle.activeOn.texture = dropDownListStyle.hover.texture;
		dropDownListStyle.fixedHeight = true;
		dropDownListStyle.fixedWidth = false;
		dropDownListStyle.height = 13;
		dropDownListStyle.width = 30;
		dropDownListStyle.contentOffset.left = 3;
		dropDownListStyle.contentOffset.right = 11;
		dropDownListStyle.contentOffset.top = 1;
		dropDownListStyle.contentOffset.bottom = 1;
		dropDownListStyle.border.left = 1;
		dropDownListStyle.border.right = 10;
		dropDownListStyle.border.top = 1;
		dropDownListStyle.border.bottom = 1;
		dropDownListStyle.font = font;
		dropDownListStyle.fontSize = DefaultFontSize;
		dropDownListStyle.textHorzAlign = THA_Left;
		dropDownListStyle.textVertAlign = TVA_Top;

		skin->setStyle("ListBox", dropDownListStyle);

		// DropDown scroll up button arrow
		GUIElementStyle dropDownScrollUpBtnArrowStyle;
		dropDownScrollUpBtnArrowStyle.normal.texture = getSkinTexture(DropDownBoxBtnUpArrowTex);
		dropDownScrollUpBtnArrowStyle.hover.texture = dropDownScrollUpBtnArrowStyle.normal.texture;
		dropDownScrollUpBtnArrowStyle.active.texture = dropDownScrollUpBtnArrowStyle.hover.texture;
		dropDownScrollUpBtnArrowStyle.fixedHeight = true;
		dropDownScrollUpBtnArrowStyle.fixedWidth = false;
		dropDownScrollUpBtnArrowStyle.height = 7;
		dropDownScrollUpBtnArrowStyle.width = 30;
		dropDownScrollUpBtnArrowStyle.border.left = 1;
		dropDownScrollUpBtnArrowStyle.border.right = 1;
		dropDownScrollUpBtnArrowStyle.border.top = 1;
		dropDownScrollUpBtnArrowStyle.border.bottom = 1;

		skin->setStyle("ListBoxScrollUpBtnArrow", dropDownScrollUpBtnArrowStyle);
		skin->setStyle("MenuBarScrollUpBtnArrow", dropDownScrollUpBtnArrowStyle);
		skin->setStyle("ContextMenuScrollUpBtnArrow", dropDownScrollUpBtnArrowStyle);

		// DropDown scroll up button
		GUIElementStyle dropDownScrollUpBtnStyle;
		dropDownScrollUpBtnStyle.normal.texture = getSkinTexture(DropDownBoxBtnUpNormalTex);
		dropDownScrollUpBtnStyle.hover.texture = getSkinTexture(DropDownBoxBtnUpHoverTex);
		dropDownScrollUpBtnStyle.active.texture = dropDownScrollUpBtnStyle.hover.texture;
		dropDownScrollUpBtnStyle.fixedHeight = true;
		dropDownScrollUpBtnStyle.fixedWidth = false;
		dropDownScrollUpBtnStyle.height = 7;
		dropDownScrollUpBtnStyle.width = 30;
		dropDownScrollUpBtnStyle.border.left = 1;
		dropDownScrollUpBtnStyle.border.right = 1;
		dropDownScrollUpBtnStyle.border.top = 1;
		dropDownScrollUpBtnStyle.border.bottom = 1;

		skin->setStyle("ListBoxScrollUpBtn", dropDownScrollUpBtnStyle);
		skin->setStyle("MenuBarScrollUpBtn", dropDownScrollUpBtnStyle);
		skin->setStyle("ContextMenuScrollUpBtn", dropDownScrollUpBtnStyle);

		// DropDown scroll down button arrow
		GUIElementStyle dropDownScrollDownBtnArrowStyle;
		dropDownScrollDownBtnArrowStyle.normal.texture = getSkinTexture(DropDownBoxBtnDownArrowTex);
		dropDownScrollDownBtnArrowStyle.hover.texture = dropDownScrollDownBtnArrowStyle.normal.texture;
		dropDownScrollDownBtnArrowStyle.active.texture = dropDownScrollDownBtnArrowStyle.hover.texture;
		dropDownScrollDownBtnArrowStyle.fixedHeight = true;
		dropDownScrollDownBtnArrowStyle.fixedWidth = false;
		dropDownScrollDownBtnArrowStyle.height = 7;
		dropDownScrollDownBtnArrowStyle.width = 30;
		dropDownScrollDownBtnArrowStyle.border.left = 1;
		dropDownScrollDownBtnArrowStyle.border.right = 1;
		dropDownScrollDownBtnArrowStyle.border.top = 1;
		dropDownScrollDownBtnArrowStyle.border.bottom = 1;

		skin->setStyle("ListBoxScrollDownBtnArrow", dropDownScrollDownBtnArrowStyle);
		skin->setStyle("MenuBarScrollDownBtnArrow", dropDownScrollDownBtnArrowStyle);
		skin->setStyle("ContextMenuScrollDownBtnArrow", dropDownScrollDownBtnArrowStyle);

		// DropDown scroll down button
		GUIElementStyle dropDownScrollDownBtnStyle;
		dropDownScrollDownBtnStyle.normal.texture = getSkinTexture(DropDownBoxBtnDownNormalTex);
		dropDownScrollDownBtnStyle.hover.texture = getSkinTexture(DropDownBoxBtnDownHoverTex);
		dropDownScrollDownBtnStyle.active.texture = dropDownScrollDownBtnStyle.hover.texture;
		dropDownScrollDownBtnStyle.fixedHeight = true;
		dropDownScrollDownBtnStyle.fixedWidth = false;
		dropDownScrollDownBtnStyle.height = 7;
		dropDownScrollDownBtnStyle.width = 30;
		dropDownScrollDownBtnStyle.border.left = 1;
		dropDownScrollDownBtnStyle.border.right = 1;
		dropDownScrollDownBtnStyle.border.top = 1;
		dropDownScrollDownBtnStyle.border.bottom = 1;

		skin->setStyle("ListBoxScrollDownBtn", dropDownScrollDownBtnStyle);
		skin->setStyle("MenuBarScrollDownBtn", dropDownScrollDownBtnStyle);
		skin->setStyle("ContextMenuScrollDownBtn", dropDownScrollDownBtnStyle);

		// DropDown entry button
		GUIElementStyle dropDownEntryBtnStyle;
		dropDownEntryBtnStyle.normal.texture = getSkinTexture(DropDownBoxEntryNormalTex);
		dropDownEntryBtnStyle.hover.texture = getSkinTexture(DropDownBoxEntryHoverTex);
		dropDownEntryBtnStyle.active.texture = dropDownEntryBtnStyle.hover.texture;
		dropDownEntryBtnStyle.normalOn.texture = dropDownEntryBtnStyle.hover.texture;
		dropDownEntryBtnStyle.hoverOn.texture = dropDownEntryBtnStyle.hover.texture;
		dropDownEntryBtnStyle.activeOn.texture = dropDownEntryBtnStyle.hover.texture;
		dropDownEntryBtnStyle.fixedHeight = true;
		dropDownEntryBtnStyle.fixedWidth = false;
		dropDownEntryBtnStyle.height = 14;
		dropDownEntryBtnStyle.width = 30;
		dropDownEntryBtnStyle.border.left = 1;
		dropDownEntryBtnStyle.border.right = 1;
		dropDownEntryBtnStyle.border.top = 1;
		dropDownEntryBtnStyle.border.bottom = 1;
		dropDownEntryBtnStyle.font = font;
		dropDownEntryBtnStyle.fontSize = DefaultFontSize;
		dropDownEntryBtnStyle.textHorzAlign = THA_Left;
		dropDownEntryBtnStyle.textVertAlign = TVA_Top;

		skin->setStyle(GUIDropDownContent::ENTRY_STYLE_TYPE, dropDownEntryBtnStyle);

		// DropDown entry button with expand
		GUIElementStyle dropDownEntryExpBtnStyle;
		dropDownEntryExpBtnStyle.normal.texture = getSkinTexture(DropDownBoxEntryExpNormalTex);
		dropDownEntryExpBtnStyle.hover.texture = getSkinTexture(DropDownBoxEntryExpHoverTex);
		dropDownEntryExpBtnStyle.active.texture = dropDownEntryExpBtnStyle.hover.texture;
		dropDownEntryExpBtnStyle.normalOn.texture = dropDownEntryExpBtnStyle.hover.texture;
		dropDownEntryExpBtnStyle.hoverOn.texture = dropDownEntryExpBtnStyle.hover.texture;
		dropDownEntryExpBtnStyle.activeOn.texture = dropDownEntryExpBtnStyle.hover.texture;
		dropDownEntryExpBtnStyle.fixedHeight = true;
		dropDownEntryExpBtnStyle.fixedWidth = false;
		dropDownEntryExpBtnStyle.height = 14;
		dropDownEntryExpBtnStyle.width = 30;
		dropDownEntryExpBtnStyle.border.left = 1;
		dropDownEntryExpBtnStyle.border.right = 6;
		dropDownEntryExpBtnStyle.border.top = 1;
		dropDownEntryExpBtnStyle.border.bottom = 1;
		dropDownEntryExpBtnStyle.font = font;
		dropDownEntryExpBtnStyle.fontSize = DefaultFontSize;
		dropDownEntryExpBtnStyle.textHorzAlign = THA_Left;
		dropDownEntryExpBtnStyle.textVertAlign = TVA_Top;

		skin->setStyle(GUIDropDownContent::ENTRY_EXP_STYLE_TYPE, dropDownEntryExpBtnStyle);

		// Drop down separator
		GUIElementStyle dropDownSeparatorStyle;
		dropDownSeparatorStyle.normal.texture = getSkinTexture(DropDownSeparatorTex);
		dropDownSeparatorStyle.fixedHeight = true;
		dropDownSeparatorStyle.fixedWidth = false;
		dropDownSeparatorStyle.height = 3;
		dropDownSeparatorStyle.width = 30;
		dropDownSeparatorStyle.border.left = 1;
		dropDownSeparatorStyle.border.right = 1;
		dropDownSeparatorStyle.border.top = 1;
		dropDownSeparatorStyle.border.bottom = 1;

		skin->setStyle(GUIDropDownContent::SEPARATOR_STYLE_TYPE, dropDownSeparatorStyle);

		// Drop down content
		GUIElementStyle dropDownContentStyle;
		dropDownContentStyle.minWidth = 50;
		dropDownContentStyle.minHeight = 20;
		dropDownContentStyle.subStyles[GUIDropDownContent::ENTRY_STYLE_TYPE] = GUIDropDownContent::ENTRY_STYLE_TYPE;
		dropDownContentStyle.subStyles[GUIDropDownContent::ENTRY_EXP_STYLE_TYPE] = GUIDropDownContent::ENTRY_EXP_STYLE_TYPE;
		dropDownContentStyle.subStyles[GUIDropDownContent::SEPARATOR_STYLE_TYPE] = GUIDropDownContent::SEPARATOR_STYLE_TYPE;

		skin->setStyle("ListBoxContent", dropDownContentStyle);
		skin->setStyle("MenuBarContent", dropDownContentStyle);
		skin->setStyle("ContextMenuContent", dropDownContentStyle);

		// DropDown box frame
		GUIElementStyle dropDownBoxStyle;
		dropDownBoxStyle.normal.texture = getSkinTexture(DropDownBoxBgTex);
		dropDownBoxStyle.hover.texture = dropDownEntryBtnStyle.normal.texture;
		dropDownBoxStyle.active.texture = dropDownEntryBtnStyle.hover.texture;
		dropDownBoxStyle.fixedHeight = false;
		dropDownBoxStyle.fixedWidth = false;
		dropDownBoxStyle.border.left = 1;
		dropDownBoxStyle.border.right = 1;
		dropDownBoxStyle.border.top = 1;
		dropDownBoxStyle.border.bottom = 1;
		dropDownBoxStyle.margins.left = 1;
		dropDownBoxStyle.margins.right = 1;
		dropDownBoxStyle.margins.top = 1;
		dropDownBoxStyle.margins.bottom = 1;

		skin->setStyle("ListBoxFrame", dropDownBoxStyle);
		skin->setStyle("MenuBarFrame", dropDownBoxStyle);
		skin->setStyle("ContextMenuFrame", dropDownBoxStyle);

		/************************************************************************/
		/* 									OTHER                      			*/
		/************************************************************************/

		// Right-aligned label
		GUIElementStyle rightAlignedLabelStyle;
		rightAlignedLabelStyle.font = font;
		rightAlignedLabelStyle.fontSize = DefaultFontSize;
		rightAlignedLabelStyle.fixedWidth = false;
		rightAlignedLabelStyle.fixedHeight = true;
		rightAlignedLabelStyle.height = 11;
		rightAlignedLabelStyle.minWidth = 10;
		rightAlignedLabelStyle.textHorzAlign = THA_Right;

		skin->setStyle("RightAlignedLabel", rightAlignedLabelStyle);

		return skin;
	}

	HSpriteTexture BuiltinResources::getSkinTexture(const WString& name)
	{
		Path texturePath = FileSystem::getWorkingDirectoryPath();
		texturePath.append(EngineSkinFolder);
		texturePath.append(L"sprite_" + name + L".asset");

		return Resources::instance().load<SpriteTexture>(texturePath);
	}

	HShader BuiltinResources::getShader(const WString& name)
	{
		Path programPath = EngineShaderFolder;
		programPath.append(name + L".asset");

		return gResources().load<Shader>(programPath);
	}

	HTexture BuiltinResources::getCursorTexture(const WString& name)
	{
		Path cursorPath = FileSystem::getWorkingDirectoryPath();
		cursorPath.append(EngineCursorFolder);
		cursorPath.append(name + L".asset");

		return Resources::instance().load<Texture>(cursorPath);
	}

	const PixelData& BuiltinResources::getCursorArrow(Vector2I& hotSpot)
	{
		hotSpot = CursorArrowHotspot;
		return *mCursorArrow.get();
	}

	const PixelData& BuiltinResources::getCursorArrowDrag(Vector2I& hotSpot)
	{
		hotSpot = CursorArrowDragHotspot;
		return *mCursorArrowDrag.get();
	}

	const PixelData& BuiltinResources::getCursorWait(Vector2I& hotSpot)
	{
		hotSpot = CursorWaitHotspot;
		return *mCursorWait.get();
	}

	const PixelData& BuiltinResources::getCursorIBeam(Vector2I& hotSpot)
	{
		hotSpot = CursorIBeamHotspot;
		return *mCursorIBeam.get();
	}

	const PixelData& BuiltinResources::getCursorSizeNESW(Vector2I& hotSpot)
	{
		hotSpot = CursorSizeNESWHotspot;
		return *mCursorSizeNESW.get();
	}

	const PixelData& BuiltinResources::getCursorSizeNS(Vector2I& hotSpot)
	{
		hotSpot = CursorSizeNSHotspot;
		return *mCursorSizeNS.get();
	}

	const PixelData& BuiltinResources::getCursorSizeNWSE(Vector2I& hotSpot)
	{
		hotSpot = CursorSizeNWSEHotspot;
		return *mCursorSizeNWSE.get();
	}

	const PixelData& BuiltinResources::getCursorSizeWE(Vector2I& hotSpot)
	{
		hotSpot = CursorSizeWEHotspot;
		return *mCursorSizeWE.get();
	}

	const PixelData& BuiltinResources::getCursorDeny(Vector2I& hotSpot)
	{
		hotSpot = CursorDenyHotspot;
		return *mCursorDeny.get();
	}

	const PixelData& BuiltinResources::getCursorMoveLeftRight(Vector2I& hotSpot)
	{
		hotSpot = CursorArrowLeftRightHotspot;
		return *mCursorArrowLeftRight.get();
	}

	GUIMaterialInfo BuiltinResources::createSpriteTextMaterial() const
	{
		GUIMaterialInfo info;
		info.material = Material::create(mShaderSpriteText);

		info.mainTexture = info.material->getParamTexture("mainTexture");
		info.mainTexSampler = info.material->getParamSamplerState("mainTexSamp");
		info.tint = info.material->getParamVec4("tint");

		return info;
	}

	GUIMaterialInfo BuiltinResources::createSpriteImageMaterial() const
	{
		GUIMaterialInfo info;
		info.material = Material::create(mShaderSpriteImage);
		info.mainTexture = info.material->getParamTexture("mainTexture");
		info.mainTexSampler = info.material->getParamSamplerState("mainTexSamp");
		info.tint = info.material->getParamVec4("tint");

		return info;
	}

	GUIMaterialInfo BuiltinResources::createSpriteNonAlphaImageMaterial() const
	{
		GUIMaterialInfo info;
		info.material = Material::create(mShaderSpriteNonAlphaImage);
		info.mainTexture = info.material->getParamTexture("mainTexture");
		info.mainTexSampler = info.material->getParamSamplerState("mainTexSamp");
		info.tint = info.material->getParamVec4("tint");

		return info;
	}

	HMaterial BuiltinResources::createDummyMaterial() const
	{
		return Material::create(mShaderDummy);
	}

	void BuiltinResourcesHelper::importAssets(const Path& inputFolder, const Path& outputFolder, const ResourceManifestPtr& manifest)
	{
		if (!FileSystem::exists(inputFolder))
			return;

		auto importResource = [&](const Path& filePath)
		{
			Path relativePath = filePath.getRelative(inputFolder);
			Path outputPath = FileSystem::getWorkingDirectoryPath() + outputFolder + relativePath;
			outputPath.setFilename(outputPath.getWFilename() + L".asset");

			HResource resource = Importer::instance().import(filePath);
			if (resource != nullptr)
			{
				Resources::instance().save(resource, outputPath, true);
				manifest->registerResource(resource.getUUID(), outputPath);
			}

			return true;
		};

		FileSystem::iterate(inputFolder, importResource);
	}

	void BuiltinResourcesHelper::importFont(const Path& inputFile, const Path& outputFolder, 
		UINT32 size, bool antialiasing, const ResourceManifestPtr& manifest)
	{
		ImportOptionsPtr fontImportOptions = Importer::instance().createImportOptions(inputFile);
		if (rtti_is_of_type<FontImportOptions>(fontImportOptions))
		{
			FontImportOptions* importOptions = static_cast<FontImportOptions*>(fontImportOptions.get());

			Vector<UINT32> fontSizes;
			fontSizes.push_back(size);
			importOptions->setFontSizes(fontSizes);
			importOptions->setAntialiasing(antialiasing);
		}
		else
			return;

		HFont font = Importer::instance().import<Font>(inputFile, fontImportOptions);

		WString fontName = inputFile.getWFilename();
		Path outputPath = FileSystem::getWorkingDirectoryPath() + outputFolder + fontName;
		outputPath.setFilename(outputPath.getWFilename() + L".asset");

		Resources::instance().save(font, outputPath, true);
		manifest->registerResource(font.getUUID(), outputPath);

		// Save font texture pages as well. TODO - Later maybe figure out a more automatic way to do this
		const FontData* fontData = font->getFontDataForSize(size);

		Path texPageOutputPath = FileSystem::getWorkingDirectoryPath() + outputFolder;

		UINT32 pageIdx = 0;
		for (auto tex : fontData->texturePages)
		{
			texPageOutputPath.setFilename(fontName + L"_texpage_" + toWString(pageIdx) + L".asset");
			Resources::instance().save(tex, texPageOutputPath, true);
			manifest->registerResource(tex.getUUID(), texPageOutputPath);
		}
	}

	void BuiltinResourcesHelper::generateSpriteTextures(const Path& folder, const ResourceManifestPtr& manifest)
	{
		if (!FileSystem::exists(folder))
			return;

		Vector<Path> filesToProcess;
		auto gather = [&](const Path& filePath)
		{
			filesToProcess.push_back(filePath);

			return true;
		};

		FileSystem::iterate(folder, gather);

		for (auto& filePath : filesToProcess)
		{
			Path outputPath = FileSystem::getWorkingDirectoryPath() + filePath;
			outputPath.setFilename(L"sprite_" + outputPath.getWFilename());

			HTexture source = gResources().load<Texture>(filePath);

			if (source != nullptr)
			{
				HSpriteTexture spriteTex = SpriteTexture::create(source);
				Resources::instance().save(spriteTex, outputPath, true);
				manifest->registerResource(spriteTex.getUUID(), outputPath);
			}
		}
	}

	void BuiltinResourcesHelper::writeTimestamp(const Path& file)
	{
		DataStreamPtr fileStream = FileSystem::createAndOpenFile(file);

		time_t currentTime = std::time(nullptr);
		fileStream->write(&currentTime, sizeof(currentTime));
		fileStream->close();
	}

	bool BuiltinResourcesHelper::checkForModifications(const Path& folder, const Path& timeStampFile)
	{
		if (!FileSystem::exists(timeStampFile))
			return true;

		DataStreamPtr fileStream = FileSystem::openFile(timeStampFile);
		time_t lastUpdateTime = 0;
		fileStream->read(&lastUpdateTime, sizeof(lastUpdateTime));
		fileStream->close();

		bool upToDate = true;
		auto checkUpToDate = [&](const Path& filePath)
		{
			time_t fileLastModified = FileSystem::getLastModifiedTime(filePath);

			if (fileLastModified > lastUpdateTime)
			{
				upToDate = false;
				return false;
			}

			return true;
		};

		FileSystem::iterate(folder, checkUpToDate, checkUpToDate);

		return !upToDate;
	}
}