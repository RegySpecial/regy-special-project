document.querySelector`#intro`.addEventListener('animationend',function(){
  this.remove()
  document.querySelector`form`.style.display="grid";
  document.querySelector`buttonGrid`.style.display="grid";
  document.body.style.backgroundImage="url(https://cdn.pixabay.com/photo/2015/06/19/21/24/avenue-815297_1280.jpg)"
  document.querySelectorAll`buttonGrid button`.forEach(button=>{
    button.addEventListener('click',function(){
      const audioContext=new AudioContext(),
            beep=new OscillatorNode(audioContext)
      beep.connect(audioContext.destination)
      beep.frequency=1000
      beep.start(0)
      beep.stop(.1)
      switch (text) {
        case 'Exit':
          window.close()
          break;
        case 'Play':
          const PlayDialog=document.createElement('dialog')
          PlayDialog.style='background:black;transition:1s height width;position:absolute;z-index:1;top:5%;width:90%;height:90%;'
          document.body.append(PlayDialog)
          PlayDialog.show()
          break;
        case 'More information':
          const PlayDialog=document.createElement('dialog')
          PlayDialog.style='background:black;transition:1s height width;position:absolute;z-index:1;top:5%;width:90%;height:90%;'
          document.body.append(PlayDialog)
          PlayDialog.show()
          break;
        case 'Options':
          const PlayDialog=document.createElement('dialog')
          PlayDialog.style='background:black;transition:1s height width;position:absolute;z-index:1;top:5%;width:90%;height:90%;'
          document.body.append(PlayDialog)
          PlayDialog.show()
          break;
      }
    })
  })
})