# CMD-Pokemon-Oyunu
Windows CMD ile basit bir pokemon oyunu (C++)
Bu proje tamamen şahsım tarafından geliştirilmiştir.
Projeyi dilediğiniz gibi geliştirebilirsiniz fakat yayınlamak için alt yapısının "Ubeyd Talha Alkan"'a ait olduğunu belirtmelisiniz.

--------------------
Kullanılan konular:

Class yapısı

Method Overload

Operator overload

Friend function

Custom Library

2 boyutlu dizilerde pointer

String

File işlemi

Pointer

Fonksiyonlar


---------------------
Nasıl kullanılır:

Öncelikle oyun Event sınıfının run() fonksiyonu ile başlar ve update() fonksiyonu çalıştırılır , fonksiyon her adımda tekrarlanır.

-----------------------------------------------------------------------
Projede 4 farklı sınıf yazılmıştır bunlar:

Event sınıfı: Oyunun çalıştığı ve olayların döndüğü sınıftır.

Pokemon sınıfı: Pokemon oluşturmaya yarayan sınıftır.

Hero sınıfı: Oyuncuyu oluşturmaya yarayan sınıftır.

Map sınıfı : haritayı oluşturmaya ve yazdırmaya yarayan sınıftır.

---------------------------------------------------------------------------
Basitçe çalışma mantığı:

Event.run() fonksiyonun içinde pokemonlar için pokemon sınıfından pokemon dizisi oluşturulur ve createPokemons() metodu ile pokemons.txt dosyasına yazdığınız pokemonlar bu diziye eklenmiş olur. 
Pokemonlart txt dosyasına şu formatta yazılmalıdır: id(int) isim(string) hasar(int) defans(int) level(int) exp(int) nadirlik(int)
Ben kolaylık olsun diye pokemon sayısını n diyerek sabit sayı yapmışım sizler dosya sonuna kadar okuma yöntemiyle daha güzel hale getirebilirsiniz.Daha sonra bir adet hero  ve map oluşturmalısınız.
map nesnesi 3 adet parametre alır uzunluk,genişlik,pokemon dizisi(pointer).

Başlangıçta hero nun pokemonu yoktur bunu oyun başlatılınca seçimle bir adet kazanmaktadır.

hero sınıfı 3 parametre alır name,kordinat x,kordinat y.Ben pokemon olmayan yerde başlasın diye haritada pokemon olmayan yer bulup başlattım.

yön okları yada wasd tuşları ile haritada heronuz baş harfi gösterilerek gezinebilirsiniz.

harita sınıfında 3 çeşit harita oluşmaktadır: Ekrana yazılan harita, pokemonların kodlandığı, ve haritanın int karşılığı

 
