
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8654);
        set_picid_2(8654);

        set_level(45);
        set_value(24000);
        set_max_lasting(7399);
        set("cp", 0);
        set("pp", 50);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
