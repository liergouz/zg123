
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("���������");
        set_picid_1(8613);
        set_picid_2(8613);

        set_level(55);
        set_value(31000);
        set_max_lasting(7699);
        set("cp", 0);
        set("pp", 55);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "���������";
}
