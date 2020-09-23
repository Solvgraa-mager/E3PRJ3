# PlantUML Gantt

Syntaxen er relativt enkel, og beskrives i detajler i [dokumentationen](https://plantuml.com/gantt-diagram).

```puml
project starts the 2020/09/07
[Last update] happens 2020/09/22 and is colored in #AAF

saturday are closed
sunday are closed

-- FASER I PROJEKTET --

[Projektdefinering] as [PD] starts the 2020/09/07 and ends at 2020/09/17

[Risk assesment & mitigation] as [RA] starts the 2020/09/17
[RA] ends 2020/10/07 and is colored in Salmon
[Kravspecifikation] as [KravSpek] starts the 2020/09/23
[KravSpek] lasts 5 days
```

Uddrag af koden til E3PRJ3 tidsplanen.
