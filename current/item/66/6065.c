
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("�����ñ");
        set_picid_1(6634);
        set_picid_2(6634);

        set_level(65);
        set_value(26300);
        set_max_lasting(7599);
        set("dp", 44);
        set("pp", 75);

        setup();

        set_gender(2);
        set_head_code(55);
}

// ��������ȡ����
string get_desc()
{
        return "�����ñ";
}
