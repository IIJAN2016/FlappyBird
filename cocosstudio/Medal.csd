<GameFile>
  <PropertyGroup Name="Medal" Type="Node" ID="d044d69a-41ad-4122-870a-e340e4b91db6" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="21" Speed="0.6667" ActivedAnimationName="effect">
        <Timeline ActionTag="-11148691" Property="Scale">
          <ScaleFrame FrameIndex="1" X="0.0100" Y="0.0100">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="5" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="7" X="0.7500" Y="0.7500">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="9" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="14" X="0.7500" Y="0.7500">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="0.0100" Y="0.0100">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-11148691" Property="VisibleForFrame">
          <BoolFrame FrameIndex="5" Tween="False" Value="True" />
          <BoolFrame FrameIndex="21" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-11148691" Property="FileData">
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="Normal" Path="Assets/effect/effect_twincle2.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="7" Tween="False">
            <TextureFile Type="Normal" Path="Assets/effect/effect_twincle1.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="15" Tween="False">
            <TextureFile Type="Normal" Path="Assets/effect/effect_twincle2.png" Plist="" />
          </TextureFrame>
        </Timeline>
        <Timeline ActionTag="-11148691" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="5" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="7" Tween="False" Src="1" Dst="771" />
          <BlendFuncFrame FrameIndex="15" Tween="False" Src="1" Dst="771" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="effect" StartIndex="1" EndIndex="21">
          <RenderColor A="150" R="34" G="139" B="34" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Medal" Tag="14" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="board" ActionTag="-250880531" Tag="24" IconVisible="False" LeftMargin="-119.0000" RightMargin="-119.0000" BottomMargin="-126.0000" ctype="SpriteObjectData">
            <Size X="238.0000" Y="126.0000" />
            <Children>
              <AbstractNodeData Name="medal_bronze" ActionTag="-661614202" VisibleForFrame="False" Tag="16" IconVisible="False" LeftMargin="33.0000" RightMargin="161.0000" TopMargin="45.0000" BottomMargin="37.0000" ctype="SpriteObjectData">
                <Size X="44.0000" Y="44.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="55.0000" Y="37.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2311" Y="0.2937" />
                <PreSize X="0.1849" Y="0.3492" />
                <FileData Type="Normal" Path="Assets/medal/medal_bronze.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="metal_silver" ActionTag="-1134793803" VisibleForFrame="False" Tag="21" IconVisible="False" LeftMargin="33.0000" RightMargin="161.0000" TopMargin="45.0000" BottomMargin="37.0000" ctype="SpriteObjectData">
                <Size X="44.0000" Y="44.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="55.0000" Y="37.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2311" Y="0.2937" />
                <PreSize X="0.1849" Y="0.3492" />
                <FileData Type="Normal" Path="Assets/medal/metal_silver.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="medal_gold" ActionTag="1238401098" VisibleForFrame="False" Tag="19" IconVisible="False" LeftMargin="33.0000" RightMargin="161.0000" TopMargin="45.0000" BottomMargin="37.0000" ctype="SpriteObjectData">
                <Size X="44.0000" Y="44.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="55.0000" Y="37.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2311" Y="0.2937" />
                <PreSize X="0.1849" Y="0.3492" />
                <FileData Type="Normal" Path="Assets/medal/medal_gold.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="metal_platium" ActionTag="288128820" VisibleForFrame="False" Tag="20" IconVisible="False" LeftMargin="33.0000" RightMargin="161.0000" TopMargin="45.0000" BottomMargin="37.0000" ctype="SpriteObjectData">
                <Size X="44.0000" Y="44.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="55.0000" Y="37.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2311" Y="0.2937" />
                <PreSize X="0.1849" Y="0.3492" />
                <FileData Type="Normal" Path="Assets/medal/metal_platium.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Assets/UI/score_frame.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="effect" ActionTag="-11148691" Tag="42" IconVisible="False" LeftMargin="-68.0000" RightMargin="62.0000" TopMargin="62.0000" BottomMargin="-68.0000" ctype="SpriteObjectData">
            <Size X="6.0000" Y="6.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-65.0000" Y="-65.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Assets/effect/effect_twincle2.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>