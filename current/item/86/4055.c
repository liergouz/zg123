
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("�������");
        set_picid_1(8603);
        set_picid_2(8603);

        set_level(55);
        set_value(34400);
        set_max_lasting(6499);
        set("cp", 0);
        set("pp", 57);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�������";
}
