
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8662);
        set_picid_2(8662);

        set_level(90);
        set_value(61500);
        set_max_lasting(7599);
        set("cp", 0);
        set("pp", 92);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
