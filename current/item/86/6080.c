
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(80);
        set_value(62000);
        set_max_lasting(5799);
        set("cp", 150);
        set("pp", 85);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
