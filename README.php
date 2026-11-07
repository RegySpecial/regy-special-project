<!doctype html>

<html>
  <body>
    <h1>Regy Special Project</h1>
    <hr>
    <h2>Prefazione:</h2>
    <hr>
    <p>Il seguente progetto ha lo scopo di sviluppare un videogioco performante indipendente da Toolkit grafici, audio, eccetera (salvo eccezioni per cui l'assenza di toolkit rende difficile la creazione, la progettazione, lo sviluppo e/o la manutenzione del software) o librerie non standard (salvo eccezioni per cui l'assenza di toolkit rende difficile la creazione, la progettazione, lo sviluppo e/o la manutenzione del software e/o l'uso delle librerie standard non è necessario) e non dipendenti dal sistema oprativo.</p>
    <hr>

    <p>Requisiti fissati:</p>
    <br>
    <ol>
      <li>Sistemi Operativi: Multipiattaforma</li>
      <li>CPU: Multipiattaforma</li>
    </ol>
    <br>
    <p>Risultati attuali:</p>
    <ol>
      <li>Sistemi Operativi: Windows,Linux,MacOS</li>
      <li>CPU: x86_64,AMD</li>
    </ol>

    <table>
      <caption>Progettazione del videogioco per sistema operativo</caption>
      <tr>
        <th>Linguaggi di programmazione</th>
        <th>Sistemi operativi</th>
        <th>Librerie</th>
      </tr>
      <tr>
        <td>C/C++</td>
        <td>Windows e cloni (React OS, GreenTeaOS)</td>
        <td>WinAPI</td>
      </tr>
      <tr>
        <td>C/C++/Go</td>
        <td>Unix e cloni (Linux, FreeBSD, NetBSD, OpenBSD...)</td>
        <td>Xorg or Wayland Graphic Server</td>
      </tr>
      <tr>
        <td>C/Swift</td>
        <td>MacOS e cloni (iOS, tvOS...)</td>
        <td>Unix system calls, AppKit, UIKit, AVKit and other Apple Frameworks</td>
      </tr>
    </table>

    <table>
      <caption>Impieghi dei linguaggi di programmazione:</caption>
      <tr>
        <th>Linguaggi di programmazione</th>
        <th>Sistema operativo</th>
        <th>Impiego</th>
      </tr>
      <tr>
        <td>C</td>
        <td>Windows e cloni (React OS, GreenTeaOS)</td>
        <td>WinAPI</td>
      </tr>
      <tr>
        <td>C++</td>
        <td>Windows e cloni (React OS, GreenTeaOS)</td>
        <td>coso</td>
      </tr>
      <tr>
        <td>Go</td>
        <td>Unix e cloni (Linux, FreeBSD, NetBSD, OpenBSD...)</td>
        <td>Xorg or Wayland Graphic Server</td>
      </tr>
      <tr>
        <td>Swift</td>
        <td>MacOS e cloni (iOS, tvOS...)</td>
        <td>Unix system calls, AppKit, UIKit, AVKit and other Apple Frameworks
      </tr>
    </table>
  </body>
</html>