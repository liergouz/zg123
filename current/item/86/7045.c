
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8657);
        set_picid_2(8657);

        set_level(45);
        set_value(30500);
        set_max_lasting(5199);
        set("cp", 80);
        set("pp", 55);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
