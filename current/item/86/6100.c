
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8655);
        set_picid_2(8655);

        set_level(100);
        set_value(80000);
        set_max_lasting(6099);
        set("cp", 190);
        set("pp", 105);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
