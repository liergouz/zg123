
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8661);
        set_picid_2(8661);

        set_level(110);
        set_value(89000);
        set_max_lasting(6199);
        set("cp", 210);
        set("pp", 120);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
