# Deadlock Pelea de Parejas
Esta es una simulación de un deadlock en lenguaje C, basada en el escenario, de una pelea de de parejas y su falta de perdón 💔 💬, descrito en esta respuesta de StackOverflow https://stackoverflow.com/a/21519666

## Idea básica
- Hilo 1: Mujer (M) 👩
- Hilo 2: Hombre (H) 👨
- Recurso 1: Pedir perdón
- Recurso 2: Aceptar el error propio

## Condiciones de Coffman
Las condiciones de Coffman necesarias para un deadlock, se cumplen en este escenario del siguiente modo:
- **Exclusión mutua:** H y M no pueden pedir perdón o aceptar el error propio a la vez
- **Retención y espera:** En un momento dado, uno de los dos retiene el aceptar el error propio mientras espera que el otro pida perdón, o uno retiene el pedir perdón mientras espera que el otro acepte su error
- **No liberación anticipada:** Nadie puede obligarlos a liberar el recurso
- **Espera circular:** El eje del problema 😠. Uno no pide perdón porque espera que el otro acepte sus errores, y el otro no acepta sus errores porque espera que el otro pida perdón
