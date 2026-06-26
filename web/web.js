document.querySelector('div#intro').addEventListener('animationend',function(){
  this.remove()
  document.body.style.backgroundImage="url(https://cdn.pixabay.com/photo/2015/06/19/21/24/avenue-815297_1280.jpg)"
  const groupButton=document.createElement('div')
  groupButton.style="display:grid;grid-template-areas:\"Play Exit\"\"Options Credits\";gap:10px 10px;width:100%;top:50%;position:absolute;"
  document.body.append(groupButton)
  for(const text of ["Play","Exit","Options","Credits"]){
    const mainButton=document.createElement('button')
    mainButton.style=`background:blue;color:red;align-text:center;grid-area:${text};border:0;`
    mainButton.className="mainButtons"
    groupButton.append(mainButton)
    mainButton.id=text
    mainButton.textContent=text
    mainButton.addEventListener('click',function(){
      const audioContext=new AudioContext(),beep=new OscillatorNode(audioContext)
      beep.connect(audioContext.destination)
      beep.frequency=1500
      beep.start(0)
      beep.stop(.1)
      switch(text){
        case'Exit':
          window.close()
          break;
        case'Play':
          const PlayDialog=document.createElement('dialog')
          PlayDialog.style='background:black;transition:1s height width;position:absolute;z-index:1;top:5%;width:90%;height:90%;'
          document.body.append(PlayDialog)
          PlayDialog.show()
          break;
      }
    })
  }
})