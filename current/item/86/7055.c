
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("ˮ������");
        set_picid_1(8653);
        set_picid_2(8653);

        set_level(55);
        set_value(39500);
        set_max_lasting(5399);
        set("cp", 100);
        set("pp", 65);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ˮ������";
}
