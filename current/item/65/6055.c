
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("����ñ");
        set_picid_1(6538);
        set_picid_2(6538);

        set_level(55);
        set_value(20700);
        set_max_lasting(6999);
        set("dp", 38);
        set("pp", 64);

        setup();

        set_gender(1);
        set_head_code(44);
}

// ��������ȡ����
string get_desc()
{
        return "����ñ";
}
