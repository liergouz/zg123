
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8650);
        set_picid_2(8650);

        set_level(60);
        set_value(44000);
        set_max_lasting(5499);
        set("cp", 108);
        set("pp", 66);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
