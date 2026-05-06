
tempi_debug = readtable("debug.csv"); 
tempi_release = readtable("relese.csv");


labels = ["Bubble","Insertion","Selection","Std","Merge","Quick","Quick opt"];


figure('Name', 'Confronto Prestazioni Sorting', 'NumberTitle', 'off');

%DEBUG
subplot(1,2,1);

semilogy(tempi_debug.Dimensione, tempi_debug.Bubblesort, 'LineWidth',1.5); hold on;
semilogy(tempi_debug.Dimensione, tempi_debug.Insertionsort, 'LineWidth',1.5);
semilogy(tempi_debug.Dimensione, tempi_debug.Selectionsort, 'LineWidth',1.5);
semilogy(tempi_debug.Dimensione, tempi_debug.Standardsort, 'LineWidth',1.5);
semilogy(tempi_debug.Dimensione, tempi_debug.Mergesort, 'LineWidth',1.5);
semilogy(tempi_debug.Dimensione, tempi_debug.Quicksort, 'LineWidth',1.5);
semilogy(tempi_debug.Dimensione, tempi_debug.QuickOttimo, 'LineWidth',1.5);
grid on;
title("Modalità Debug (Senza Ottimizzazioni)");
xlabel("Dimensione Vettore");
ylabel("Tempo medio (s)");
legend(labels, 'Location','northwest');

%RELEASE
subplot(1,2,2);
semilogy(tempi_release.Dimensione, tempi_release.Bubblesort, 'LineWidth',1.5); hold on;
semilogy(tempi_release.Dimensione, tempi_release.Insertionsort, 'LineWidth',1.5);
semilogy(tempi_release.Dimensione, tempi_release.Selectionsort, 'LineWidth',1.5);
semilogy(tempi_release.Dimensione, tempi_release.Standardsort, 'LineWidth',1.5);
semilogy(tempi_release.Dimensione, tempi_release.Mergesort, 'LineWidth',1.5);
semilogy(tempi_release.Dimensione, tempi_release.Quicksort, 'LineWidth',1.5);
semilogy(tempi_release.Dimensione, tempi_release.QuickOttimo, 'LineWidth',1.5);
grid on;
title("Modalità Release (Ottimizzata -O3)");
xlabel("Dimensione Vettore");
ylabel("Tempo medio (s)");
legend(labels, 'Location','northwest');